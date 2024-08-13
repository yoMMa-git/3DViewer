#include "messagewidget.h"

#include "ui_messagewidget.h"

MessageWidget::MessageWidget(QWidget *parent)
    : QWidget(parent), ui(new Ui::MessageWidget) {
  ui->setupUi(this);
  connect(ui->pushButtonClose, SIGNAL(clicked()), this, SLOT(hideMessage()));
  connect(&message_timer_, SIGNAL(timeout()), this,
          SLOT(decreaseMessageOpacity()));
  connect(&message_pause_, SIGNAL(timeout()), this, SLOT(messagePauseEnded()));
  message_opacity_ = new QGraphicsOpacityEffect(this);
  hideMessage();
}

MessageWidget::~MessageWidget() { delete ui; }

void MessageWidget::showMessage(QString text, QString color) {
  ui->widgetCell->setStyleSheet(WIDGET_MESSAGE_STYLESHEET +
                                " QWidget { background: " + color + "; }");
  ui->labelMessage->setText(text);
  this->show();
  stopMessage();
  message_pause_.start(MESSAGE_PAUSE_MS);
}

void MessageWidget::stopMessage() {
  message_opacity_value_ = 1.0;
  message_opacity_->setOpacity(message_opacity_value_);
  this->setGraphicsEffect(message_opacity_);
  message_pause_.stop();
  message_timer_.stop();
}

void MessageWidget::hideMessage() {
  this->hide();
  message_pause_.stop();
  message_timer_.stop();
}

void MessageWidget::messagePauseEnded() {
  message_pause_.stop();
  message_timer_.start(DECREASE_OPACITY_STEP_MS);
}

void MessageWidget::decreaseMessageOpacity() {
  message_opacity_value_ -= static_cast<qreal>(DECREASE_OPACITY_STEP_MS) /
                            static_cast<qreal>(DECREASE_OPACITY_DURATION_MS);
  message_opacity_->setOpacity(message_opacity_value_);
  this->setGraphicsEffect(message_opacity_);
  if (message_opacity_value_ <= 0.0) {
    hideMessage();
    message_timer_.stop();
  }
}

#if QT_VERSION >= QT_VERSION_CHECK(6, 0, 0)
void MessageWidget::enterEvent(QEnterEvent *event) {
#else
void MessageWidget::enterEvent(QEvent *event) {
#endif
  event->accept();
  stopMessage();
}

void MessageWidget::leaveEvent(QEvent *event) {
  event->accept();
  message_pause_.start(MESSAGE_PAUSE_MS);
}
