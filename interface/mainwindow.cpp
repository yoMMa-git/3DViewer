#include "mainwindow.h"

#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
  ui->setupUi(this);
  gl_settings_ = new QSettings("config.ini", QSettings::IniFormat);
  connectSignals();
  setInitialState();
}

MainWindow::~MainWindow() {
  saveSettings();
  delete gl_settings_;
  delete gif_;
  delete ui;
}

void MainWindow::resizeEvent(QResizeEvent *event) {
  event->accept();
  ui->widgetMessage->hideMessage();
  moveView();
}

void MainWindow::setInitialState() {
  showAll();
  showControlPanel();
  showSettings();
  showExport();
  renewScaleLabel();
  setFonts();
  setStyle();
  setUiSettings();
  loadSettings();
}

void MainWindow::setStyle() {
#ifdef __APPLE__
  foreach (QLineEdit *line, findChildren<QLineEdit *>()) {
    line->setAttribute(Qt::WA_MacShowFocusRect, 0);
  }
  foreach (QDoubleSpinBox *box, findChildren<QDoubleSpinBox *>()) {
    box->setAttribute(Qt::WA_MacShowFocusRect, 0);
    box->setStyleSheet("QDoubleSpinBox{padding: 0 5px;}");
  }
  foreach (QSpinBox *box, findChildren<QSpinBox *>()) {
    box->setAttribute(Qt::WA_MacShowFocusRect, 0);
    box->setStyleSheet("QSpinBox{padding: 0 5px;}");
  }
  foreach (QComboBox *box, findChildren<QComboBox *>()) {
    box->setStyleSheet("QComboBox{padding: 0 5px;}");
  }
  ui->lineEditPath->setStyleSheet("QLineEdit{padding: 0 8px;}");
#else
  foreach (QLineEdit *line, findChildren<QLineEdit *>()) {
    line->setStyleSheet("QLineEdit{padding: 0;}");
  }
  foreach (QDoubleSpinBox *box, findChildren<QDoubleSpinBox *>()) {
    box->setStyleSheet("QDoubleSpinBox{padding: 0 -8px 0 -5px;}");
  }
  foreach (QSpinBox *box, findChildren<QSpinBox *>()) {
    box->setStyleSheet("QSpinBox{padding: 0 -8px 0 -5px;}");
  }
  foreach (QComboBox *box, findChildren<QComboBox *>()) {
    box->setStyleSheet("QComboBox{padding: 0 6px;}");
  }
  ui->lineEditPath->setStyleSheet("QLineEdit{padding: 0 1px;}");
#endif
}

void MainWindow::setFonts() {
  QFont common_font = FONT_COMMON;
  QFont button_font = FONT_BUTTON;
  QFont label_font = FONT_LABEL;
  if (devicePixelRatio() >= 2.0) {
    common_font = FONT_COMMON_RETINA;
    button_font = FONT_BUTTON_RETINA;
    label_font = FONT_LABEL_RETINA;
  }
  QApplication::setFont(common_font);
  foreach (QWidget *widget, QApplication::allWidgets()) {
    widget->setFont(QApplication::font());
    widget->update();
  }
  foreach (QPushButton *button, findChildren<QPushButton *>()) {
    button->setFont(button_font);
    button->update();
  }
  foreach (QLabel *label, findChildren<QLabel *>()) {
    label->setFont(label_font);
    label->update();
  }
}

void MainWindow::connectSignals() {
  connect(ui->widgetView, SIGNAL(resized()), this, SLOT(resizePanel()));
  connect(ui->pushButtonHidder, SIGNAL(clicked()), this,
          SLOT(showHidePanels()));
  connect(ui->pushButtonHideAll, SIGNAL(clicked()), this, SLOT(hideAll()));
  connect(ui->pushButtonShowAll, SIGNAL(clicked()), this, SLOT(showAll()));
  connect(ui->pushButtonControlShow, SIGNAL(clicked()), this,
          SLOT(showControlPanel()));
  connect(ui->pushButtonControlHide, SIGNAL(clicked()), this,
          SLOT(hideControlPanel()));
  connect(ui->pushButtonSettingsShow, SIGNAL(clicked()), this,
          SLOT(showSettings()));
  connect(ui->pushButtonSettingsHide, SIGNAL(clicked()), this,
          SLOT(hideSettings()));
  connect(ui->pushButtonExportShow, SIGNAL(clicked()), this,
          SLOT(showExport()));
  connect(ui->pushButtonExportHide, SIGNAL(clicked()), this,
          SLOT(hideExport()));
  connect(ui->pushButtonOpenFile, SIGNAL(clicked()), this, SLOT(findFile()));
  connect(ui->pushButtonStart, SIGNAL(clicked()), this, SLOT(loadFile()));
  connect(ui->pushButtonReset, SIGNAL(clicked()), this, SLOT(resetModel()));
  connect(ui->pushButtonScaleMinus, SIGNAL(clicked()), this,
          SLOT(rescaleMinus()));
  connect(ui->pushButtonScalePlus, SIGNAL(clicked()), this,
          SLOT(rescalePlus()));
  connect(ui->pushButtonShiftXMinus, SIGNAL(clicked()), this,
          SLOT(shiftXMinus()));
  connect(ui->pushButtonShiftXPlus, SIGNAL(clicked()), this,
          SLOT(shiftXPlus()));
  connect(ui->pushButtonShiftYMinus, SIGNAL(clicked()), this,
          SLOT(shiftYMinus()));
  connect(ui->pushButtonShiftYPlus, SIGNAL(clicked()), this,
          SLOT(shiftYPlus()));
  connect(ui->pushButtonShiftZMinus, SIGNAL(clicked()), this,
          SLOT(shiftZMinus()));
  connect(ui->pushButtonShiftZPlus, SIGNAL(clicked()), this,
          SLOT(shiftZPlus()));
  connect(ui->pushButtonRotationXMinus, SIGNAL(clicked()), this,
          SLOT(rotateXMinus()));
  connect(ui->pushButtonRotationXPlus, SIGNAL(clicked()), this,
          SLOT(rotateXPlus()));
  connect(ui->pushButtonRotationYMinus, SIGNAL(clicked()), this,
          SLOT(rotateYMinus()));
  connect(ui->pushButtonRotationYPlus, SIGNAL(clicked()), this,
          SLOT(rotateYPlus()));
  connect(ui->pushButtonRotationZMinus, SIGNAL(clicked()), this,
          SLOT(rotateZMinus()));
  connect(ui->pushButtonRotationZPlus, SIGNAL(clicked()), this,
          SLOT(rotateZPlus()));

  connect(ui->widgetView, SIGNAL(scaleChanged()), this,
          SLOT(renewScaleLabel()));

  connect(ui->toolButtonDotColor, SIGNAL(clicked()), this, SLOT(newDotColor()));
  connect(ui->toolButtonLineColor, SIGNAL(clicked()), this,
          SLOT(newLineColor()));
  connect(ui->toolButtonBackColor, SIGNAL(clicked()), this,
          SLOT(newBackgroundColor()));
  connect(ui->pushButtonSaveSettings, SIGNAL(clicked()), this,
          SLOT(saveSettings()));
  connect(ui->pushButtonLoadSettings, SIGNAL(clicked()), this,
          SLOT(loadSettings()));
  connect(ui->pushButtonDefaultSettings, SIGNAL(clicked()), this,
          SLOT(setDefaultSettings()));
  connect(ui->checkBoxMoveCameraZ, SIGNAL(stateChanged(int)), this,
          SLOT(moveCameraZChanged(int)));
  connect(ui->checkBoxShowAxis, SIGNAL(stateChanged(int)), this,
          SLOT(showAxisChanged(int)));
  connect(ui->comboBoxProjection, SIGNAL(activated(int)), this,
          SLOT(projectionChanged(int)));
  connect(ui->comboBoxDotType, SIGNAL(activated(int)), this,
          SLOT(dotTypeChanged(int)));
  connect(ui->comboBoxLineType, SIGNAL(activated(int)), this,
          SLOT(lineTypeChanged(int)));
  connect(ui->comboBoxLineStipple, SIGNAL(activated(int)), this,
          SLOT(lineStippleChanged(int)));
  connect(ui->doubleSpinBoxLineWidth, SIGNAL(valueChanged(double)), this,
          SLOT(lineWidthChanged(double)));
  connect(ui->doubleSpinBoxDotSize, SIGNAL(valueChanged(double)), this,
          SLOT(dotSizeChanged(double)));
  connect(ui->horizontalSliderCameraZ, SIGNAL(valueChanged(int)), this,
          SLOT(cameraShiftZChanged(int)));

  connect(ui->pushButtonJpeg, SIGNAL(clicked()), this, SLOT(exportImage()));
  connect(ui->pushButtonBmp, SIGNAL(clicked()), this, SLOT(exportImage()));
  connect(ui->pushButtonGif, SIGNAL(clicked()), this, SLOT(exportGifStart()));
  connect(&f_timer_, SIGNAL(timeout()), this, SLOT(exportGifEnd()));
}

/* Slots begin */
/* Appearance begin */
void MainWindow::resizePanel() {
  if (ui->widgetPanel->isHidden() == false) {
    if (ui->widgetView->height() > sumWidgetHeights()) return;
    hideExport();
    if (ui->widgetView->height() > sumWidgetHeights()) return;
    hideSettings();
    if (ui->widgetView->height() > sumWidgetHeights()) return;
    hideControlPanel();
  }
}

void MainWindow::showHidePanels() {
  if (ui->widgetControlPanel->isHidden() && ui->widgetSettings->isHidden() &&
      ui->widgetExport->isHidden()) {
    showControlPanel();
    showSettings();
    showExport();
  } else {
    hideControlPanel();
    hideSettings();
    hideExport();
  }
  moveView();
}

void MainWindow::showAll() {
  ui->widgetPanel->show();
  ui->pushButtonShowAll->hide();
  resizePanel();
  moveView();
}

void MainWindow::hideAll() {
  ui->widgetPanel->hide();
  ui->pushButtonShowAll->show();
  moveView();
}

void MainWindow::showControlPanel() {
  ui->widgetControlPanel->show();
  ui->pushButtonControlShow->hide();
  moveView();
}

void MainWindow::hideControlPanel() {
  ui->widgetControlPanel->hide();
  ui->pushButtonControlShow->show();
  moveView();
}

void MainWindow::showSettings() {
  ui->widgetSettings->show();
  ui->pushButtonSettingsShow->hide();
  moveView();
}

void MainWindow::hideSettings() {
  ui->widgetSettings->hide();
  ui->pushButtonSettingsShow->show();
  moveView();
}

void MainWindow::showExport() {
  ui->widgetExport->show();
  ui->pushButtonExportShow->hide();
  moveView();
}

void MainWindow::hideExport() {
  ui->widgetExport->hide();
  ui->pushButtonExportShow->show();
  moveView();
}
/* Appearance end */

/* Usage begin */
void MainWindow::findFile() {
  QString file_name = QFileDialog::getOpenFileName(this, tr("Open .obj file"),
                                                   "~", tr("Files (*.obj)"), 0);
  if (!file_name.isEmpty() && !file_name.isNull()) {
    ui->lineEditPath->setText(file_name);
  }
}

void MainWindow::loadFile() {
  if (ui->lineEditPath->text().isEmpty() == true) {
    showMessage("No file selected.", ui->widgetMessage->WARNING_COLOR);
  } else {
    try {
      load_timer_.start();
      ui->widgetView->loadFile(ui->lineEditPath->text().toStdString());
      setFileInfo();
      renewScaleLabel();
      showMessage("Successfully loaded in " +
                      QString::number(load_timer_.elapsed()) + " ms.",
                  ui->widgetMessage->SUCCESS_COLOR);
    } catch (const std::invalid_argument &exception) {
      showMessage(exception.what(), ui->widgetMessage->ERROR_COLOR);
      closeModel();
    } catch (...) {
      showMessage("Unknown error.", ui->widgetMessage->ERROR_COLOR);
      closeModel();
    }
    ui->widgetView->update();
  }
}

void MainWindow::resetModel() {
  ui->widgetView->reinstateData();
  ui->widgetView->update();
  renewScaleLabel();
}

void MainWindow::closeModel() {
  clearFileInfo();
  ui->widgetView->closeObject();
  ui->widgetView->update();
  renewScaleLabel();
}
/* Usage end */

/* Control begin */
void MainWindow::rescaleMinus() {
  double new_scale = 1.0 - ui->doubleSpinBoxScale->value() / 100.0;
  if (ui->widgetView->checkScaleValue(new_scale)) {
    ui->widgetView->rescale(new_scale);
    ui->widgetView->update();
    renewScaleLabel();
  }
}
void MainWindow::rescalePlus() {
  double new_scale = 1.0 + ui->doubleSpinBoxScale->value() / 100.0;
  if (ui->widgetView->checkScaleValue(new_scale)) {
    ui->widgetView->rescale(new_scale);
    ui->widgetView->update();
    renewScaleLabel();
  }
}
void MainWindow::shiftXMinus() {
  ui->widgetView->shiftX(-ui->doubleSpinBoxShiftX->value() / 100.0);
  ui->widgetView->update();
}
void MainWindow::shiftXPlus() {
  ui->widgetView->shiftX(ui->doubleSpinBoxShiftX->value() / 100.0);
  ui->widgetView->update();
}
void MainWindow::shiftYMinus() {
  ui->widgetView->shiftY(-ui->doubleSpinBoxShiftY->value() / 100.0);
  ui->widgetView->update();
}
void MainWindow::shiftYPlus() {
  ui->widgetView->shiftY(ui->doubleSpinBoxShiftY->value() / 100.0);
  ui->widgetView->update();
}
void MainWindow::shiftZMinus() {
  ui->widgetView->shiftZ(-ui->doubleSpinBoxShiftZ->value() / 100.0);
  ui->widgetView->update();
}
void MainWindow::shiftZPlus() {
  ui->widgetView->shiftZ(ui->doubleSpinBoxShiftZ->value() / 100.0);
  ui->widgetView->update();
}
void MainWindow::rotateXMinus() {
  ui->widgetView->rotateX(-ui->doubleSpinBoxRotationX->value() / 100.0);
  ui->widgetView->update();
}
void MainWindow::rotateXPlus() {
  ui->widgetView->rotateX(ui->doubleSpinBoxRotationX->value() / 100.0);
  ui->widgetView->update();
}
void MainWindow::rotateYMinus() {
  ui->widgetView->rotateY(-ui->doubleSpinBoxRotationY->value() / 100.0);
  ui->widgetView->update();
}
void MainWindow::rotateYPlus() {
  ui->widgetView->rotateY(ui->doubleSpinBoxRotationY->value() / 100.0);
  ui->widgetView->update();
}
void MainWindow::rotateZMinus() {
  ui->widgetView->rotateZ(-ui->doubleSpinBoxRotationZ->value() / 100.0);
  ui->widgetView->update();
}
void MainWindow::rotateZPlus() {
  ui->widgetView->rotateZ(ui->doubleSpinBoxRotationZ->value() / 100.0);
  ui->widgetView->update();
}
/* Control end */

/* Settings begin */
void MainWindow::setDefaultSettings() {
  ui->widgetView->settings_.setDefault();
  setUiSettings();
  ui->widgetView->update();
}

void MainWindow::loadSettings() {
  ui->widgetView->settings_.setProjection(
      static_cast<OpenGLSettings::ProjectionType>(
          gl_settings_->value("Projection", OpenGLSettings::DEFAULT_PROJECTION)
              .toInt()));
  ui->widgetView->settings_.setDotType(static_cast<OpenGLSettings::DotType>(
      gl_settings_->value("Dot/type", OpenGLSettings::DEFAULT_DOT_TYPE)
          .toInt()));
  ui->widgetView->settings_.setLineType(static_cast<OpenGLSettings::LineType>(
      gl_settings_->value("Line/type", OpenGLSettings::DEFAULT_LINE_TYPE)
          .toInt()));
  ui->widgetView->settings_.setShowAxis(
      gl_settings_->value("Show/axis", OpenGLSettings::DEFAULT_SHOW_AXIS)
          .toBool());
  ui->widgetView->settings_.setColorDot(
      gl_settings_->value("Dot/color", OpenGLSettings::DEFAULT_COLOR_DOT)
          .value<QColor>());
  ui->widgetView->settings_.setColorLine(
      gl_settings_->value("Line/color", OpenGLSettings::DEFAULT_COLOR_LINE)
          .value<QColor>());
  ui->widgetView->settings_.setColorBackground(
      gl_settings_
          ->value("Background/color", OpenGLSettings::DEFAULT_COLOR_BACKGROUND)
          .value<QColor>());
  ui->widgetView->settings_.setDotSize(
      gl_settings_->value("Dot/size", OpenGLSettings::DEFAULT_DOT_SIZE)
          .toFloat());
  ui->widgetView->settings_.setLineWidth(
      gl_settings_->value("Line/width", OpenGLSettings::DEFAULT_LINE_WIDTH)
          .toFloat());
  ui->widgetView->settings_.setStippleType(
      gl_settings_
          ->value("Line/stipple/type", OpenGLSettings::DEFAULT_STIPPLE_TYPE)
          .toInt());
  ui->widgetView->settings_.setMoveCameraZ(
      gl_settings_->value("Adjust/Z", OpenGLSettings::DEFAULT_MOVE_CAMERA_Z)
          .toBool());
  ui->widgetView->settings_.setCameraShiftZ(
      gl_settings_
          ->value("Camera/Shift/Z", OpenGLSettings::DEFAULT_CAMERA_SHIFT_Z)
          .toDouble());
  ui->widgetView->update();
  setUiSettings();
}

void MainWindow::setUiSettings() {
  ui->comboBoxProjection->setCurrentIndex(
      ui->widgetView->settings_.getProjection());
  ui->comboBoxDotType->setCurrentIndex(ui->widgetView->settings_.getDotType());
  ui->comboBoxLineType->setCurrentIndex(
      ui->widgetView->settings_.getLineType());
  ui->checkBoxShowAxis->setChecked(ui->widgetView->settings_.getShowAxis());
  ui->toolButtonDotColor->setStyleSheet(
      QString("QToolButton { background: %1; }")
          .arg(ui->widgetView->settings_.getColorDot().name()));
  ui->toolButtonLineColor->setStyleSheet(
      QString("QToolButton { background: %1; }")
          .arg(ui->widgetView->settings_.getColorLine().name()));
  ui->toolButtonBackColor->setStyleSheet(
      QString("QToolButton { background: %1; }")
          .arg(ui->widgetView->settings_.getColorBackground().name()));
  ui->doubleSpinBoxDotSize->setValue(ui->widgetView->settings_.getDotSize());
  ui->doubleSpinBoxLineWidth->setValue(
      ui->widgetView->settings_.getLineWidth());
  ui->comboBoxLineStipple->setCurrentIndex(
      ui->widgetView->settings_.getStippleType());
  ui->checkBoxMoveCameraZ->setChecked(
      ui->widgetView->settings_.getMoveCameraZ());
  ui->horizontalSliderCameraZ->setValue(
      ui->widgetView->settings_.getCameraShiftZ() * 2.0);
}

void MainWindow::saveSettings() {
  gl_settings_->setValue("Projection",
                         ui->widgetView->settings_.getProjection());
  gl_settings_->setValue("Dot/type", ui->widgetView->settings_.getDotType());
  gl_settings_->setValue("Line/type", ui->widgetView->settings_.getLineType());
  gl_settings_->setValue("Show/axis", ui->widgetView->settings_.getShowAxis());
  gl_settings_->setValue("Dot/color", ui->widgetView->settings_.getColorDot());
  gl_settings_->setValue("Line/color",
                         ui->widgetView->settings_.getColorLine());
  gl_settings_->setValue("Background/color",
                         ui->widgetView->settings_.getColorBackground());
  gl_settings_->setValue("Dot/size", ui->widgetView->settings_.getDotSize());
  gl_settings_->setValue("Line/width",
                         ui->widgetView->settings_.getLineWidth());
  gl_settings_->setValue("Line/stipple/type",
                         ui->widgetView->settings_.getStippleType());
  gl_settings_->setValue("Adjust/Z",
                         ui->widgetView->settings_.getMoveCameraZ());
  gl_settings_->setValue("Camera/Shift/Z",
                         ui->widgetView->settings_.getCameraShiftZ());
}

void MainWindow::newBackgroundColor() {
  QColor color =
      QColorDialog::getColor(ui->widgetView->settings_.getColorBackground());
  if (color.isValid()) {
    ui->widgetView->settings_.setColorBackground(color);
    ui->toolButtonBackColor->setStyleSheet(
        QString("QToolButton { background: %1; }").arg(color.name()));
    ui->widgetView->update();
  }
}

void MainWindow::newDotColor() {
  QColor color =
      QColorDialog::getColor(ui->widgetView->settings_.getColorDot());
  if (color.isValid()) {
    ui->widgetView->settings_.setColorDot(color);
    ui->toolButtonDotColor->setStyleSheet(
        QString("QToolButton { background: %1; }").arg(color.name()));
    ui->widgetView->update();
  }
}

void MainWindow::newLineColor() {
  QColor color =
      QColorDialog::getColor(ui->widgetView->settings_.getColorLine());
  if (color.isValid()) {
    ui->widgetView->settings_.setColorLine(color);
    ui->toolButtonLineColor->setStyleSheet(
        QString("QToolButton { background: %1; }").arg(color.name()));
    ui->widgetView->update();
  }
}

void MainWindow::moveCameraZChanged(int value) {
  ui->widgetView->settings_.setMoveCameraZ(value);
  ui->widgetView->update();
}
void MainWindow::showAxisChanged(int value) {
  ui->widgetView->settings_.setShowAxis(value);
  ui->widgetView->update();
}
void MainWindow::projectionChanged(int value) {
  ui->widgetView->settings_.setProjection(
      static_cast<OpenGLSettings::ProjectionType>(value));
  ui->widgetView->update();
}
void MainWindow::dotTypeChanged(int value) {
  ui->widgetView->settings_.setDotType(
      static_cast<OpenGLSettings::DotType>(value));
  ui->widgetView->update();
}
void MainWindow::lineTypeChanged(int value) {
  ui->widgetView->settings_.setLineType(
      static_cast<OpenGLSettings::LineType>(value));
  ui->widgetView->update();
}
void MainWindow::lineStippleChanged(int value) {
  ui->widgetView->settings_.setStippleType(value);
  ui->widgetView->update();
}
void MainWindow::dotSizeChanged(double value) {
  ui->widgetView->settings_.setDotSize(value);
  ui->widgetView->update();
}
void MainWindow::lineWidthChanged(double value) {
  ui->widgetView->settings_.setLineWidth(value);
  ui->widgetView->update();
}
void MainWindow::cameraShiftZChanged(int value) {
  ui->widgetView->settings_.setCameraShiftZ(static_cast<double>(value) / 2.0);
  ui->widgetView->update();
}
/* Settings end */

/* Export begin */
void MainWindow::exportImage() {
  QString extension, path = chooseDirectory();
  if (sender() == ui->pushButtonBmp)
    extension = "BMP";
  else
    extension = "JPEG";
  if (!path.isEmpty() && !path.isNull()) {
    QString str = "screenshot_" + currentDateTime() + "." + extension.toLower();
    moveView(true);
    ui->widgetView->grabFramebuffer().save(path + "/" + str,
                                           extension.toUtf8());
    if (QFile::exists(path + "/" + str) == true) {
      showMessage("File \"" + str + "\" exported.",
                  ui->widgetMessage->SUCCESS_COLOR);
    } else {
      showMessage("Export failed.", ui->widgetMessage->ERROR_COLOR);
    }
  }
  moveView(false);
}

void MainWindow::exportGifStart() {
  moveView(true);
  delete gif_;
  miliseconds_ = 0;
  gif_ = new QGifImage();
  gif_->setDefaultDelay(GIF_TIMEOUT_MSEC);
  gif_->loopCount();
  f_timer_.start(GIF_TIMEOUT_MSEC);
}

void MainWindow::exportGifEnd() {
  if (ui->pushButtonGifHD->isChecked() == true)
    gif_->addFrame(ui->widgetView->grabFramebuffer().scaled(
                       ui->widgetView->width(), ui->widgetView->height()),
                   GIF_FRAME_APPEND_DELAY_MSEC);
  else
    gif_->addFrame(
        ui->widgetView->grabFramebuffer().scaled(GIF_WIDTH_RES, GIF_HEIGHT_RES),
        GIF_FRAME_APPEND_DELAY_MSEC);
  miliseconds_ += GIF_STEP_MSEC;
  ui->progressBarGif->setValue(miliseconds_);
  if (miliseconds_ >= GIF_ENDTIME_MSEC) {
    f_timer_.stop();
    saveGif();
    ui->progressBarGif->setValue(0);
  }
}

void MainWindow::saveGif() {
  QString path = chooseDirectory();
  if (!path.isEmpty() && !path.isNull()) {
    QString str = "screencast_" + currentDateTime() + ".gif";
    gif_->save(path + "/" + str);
    if (QFile::exists(path + "/" + str) == true) {
      showMessage("File \"" + str + "\" exported.",
                  ui->widgetMessage->SUCCESS_COLOR);
    } else {
      showMessage("Export failed.", ui->widgetMessage->ERROR_COLOR);
    }
  }
  moveView(false);
}
/* Export end */

/* Misc begin */
void MainWindow::renewScaleLabel() {
  ui->labelScaleValue->setText(
      QString::number(ui->widgetView->getScaleValue() * 100.0, 'f', 2) + "%");
}
/* Misc end */
/* Slots end */

/* Misc start */
int MainWindow::sumWidgetHeights() {
  int sum_heights = ui->widgetPanel->layout()->spacing() * PANEL_WIDGETS_NUM;
  sum_heights += ui->widgetFile->height();
  if (ui->widgetControlPanel->isHidden() == false)
    sum_heights += ui->widgetControlPanel->height();
  else
    sum_heights += ui->pushButtonControlShow->height();
  if (ui->widgetSettings->isHidden() == false)
    sum_heights += ui->widgetSettings->height();
  else
    sum_heights += ui->pushButtonSettingsShow->height();
  if (ui->widgetExport->isHidden() == false)
    sum_heights += ui->widgetExport->height();
  else
    sum_heights += ui->pushButtonExportShow->height();
  return sum_heights;
}

void MainWindow::moveView(bool fullscreen) {
  if (fullscreen == true || ui->widgetPanel->isHidden() == true ||
      sumWidgetHeights() <= ui->widgetView->height() / 2) {
    ui->widgetView->setWidgetLeftShiftX(0);
  } else {
    ui->widgetView->setWidgetLeftShiftX(ui->widgetPanel->width());
  }
}

void MainWindow::clearFileInfo() {
  ui->labelFileInfo->setText("File:\nSize:\nVertices:\nEdges:\n");
}

void MainWindow::setFileInfo() {
  std::string file_name_str, size_str;
  file_name_str = ui->lineEditPath->text().toStdString();
  file_name_str = file_name_str.substr(file_name_str.find_last_of("/\\") + 1);
  size_str = getFileSizeString();

  std::stringstream result;
  result.setf(std::ios::fixed);
  result.precision(2);
  result << "File: " << file_name_str << "\nSize: " << size_str
         << "\nVertices: " << ui->widgetView->getVerticesNumber()
         << "\nEdges: " << ui->widgetView->getEdgesNumber();

  ui->labelFileInfo->setText(QString::fromStdString(result.str()));
}

size_t MainWindow::getFileSize() {
  FILE *file_ptr = NULL;
  file_ptr = fopen(ui->lineEditPath->text().toStdString().c_str(), "rb");
  fseek(file_ptr, 0, SEEK_END);
  size_t file_size = ftell(file_ptr);
  fclose(file_ptr);
  return file_size;
}

std::string MainWindow::getFileSizeString() {
  size_t size = getFileSize();
  char size_char[MAX_NUMBER_CHARS] = "";
  if (size < 100) {
    std::snprintf(size_char, MAX_NUMBER_CHARS, "%lu B", size);
  } else if (size < 100000) {
    std::snprintf(size_char, MAX_NUMBER_CHARS, "%.2f Kb",
                  static_cast<double>(size) * 1e-3);
  } else {
    std::snprintf(size_char, MAX_NUMBER_CHARS, "%.2f Mb",
                  static_cast<double>(size) * 1e-6);
  }
  return std::string(size_char);
}

QString MainWindow::chooseDirectory() {
  return QFileDialog::getExistingDirectory(this, ("Select directory"),
                                           QDir::currentPath(),
                                           QFileDialog::ShowDirsOnly);
}

QString MainWindow::currentDateTime() {
  QDateTime date = QDateTime::currentDateTime();
  QString formattedTime = date.toString("ddMMyy_hhmmss");
  return formattedTime;
}

void MainWindow::showMessage(QString text, QString color) {
  int x = static_cast<int>(text.toStdString().size()) * SYMBOL_PIXELS;
  ui->widgetMessage->setGeometry(width() - x - MESSAGE_MARGIN, MESSAGE_MARGIN,
                                 x, ui->widgetMessage->height());
  ui->widgetMessage->showMessage(text, color);
}
/* Misc end */
