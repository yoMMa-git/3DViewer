#ifndef MESSAGEWIDGET_H
#define MESSAGEWIDGET_H

#include <QEnterEvent>
#include <QGraphicsOpacityEffect>
#include <QTimer>
#include <QWidget>

namespace Ui {
class MessageWidget;
}

class MessageWidget : public QWidget {
  Q_OBJECT

 public:
  explicit MessageWidget(QWidget *parent = nullptr);
  ~MessageWidget();

  const QString SUCCESS_COLOR = QString("rgba(111, 246, 143, 255)");
  const QString ERROR_COLOR = QString("rgba(238, 68, 71, 255)");
  const QString WARNING_COLOR = QString("rgba(255, 173, 51, 255)");

  void showMessage(QString text, QString color);

 public slots:
  void hideMessage();

 private slots:
  void stopMessage();
  void messagePauseEnded();
  void decreaseMessageOpacity();

 protected:
#if QT_VERSION >= QT_VERSION_CHECK(6, 0, 0)
  void enterEvent(QEnterEvent *event) override;
#else
  void enterEvent(QEvent *event) override;
#endif
  void leaveEvent(QEvent *event) override;

 private:
  Ui::MessageWidget *ui;

  QTimer message_pause_;
  QTimer message_timer_;
  QGraphicsOpacityEffect *message_opacity_;
  qreal message_opacity_value_ = 1.0;

  static const int MESSAGE_PAUSE_MS = 2000;
  static const int DECREASE_OPACITY_STEP_MS = 25;
  static const int DECREASE_OPACITY_DURATION_MS = 5000;
  const QString WIDGET_MESSAGE_STYLESHEET =
      QString("QWidget {border-radius: 10px;}");
};

#endif  // MESSAGEWIDGET_H
