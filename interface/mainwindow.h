#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QColorDialog>
#include <QDateTime>
#include <QFileDialog>
#include <QImage>
#include <QMainWindow>
#include <QMessageBox>
#include <QMetaType>
#include <QPainter>
#include <QProgressDialog>
#include <QSettings>
#include <QThread>
#include <QTimer>

#include "qgifimage.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
  Q_OBJECT

 public:
  MainWindow(QWidget* parent = nullptr);
  ~MainWindow();

 protected:
  void resizeEvent(QResizeEvent* event) override;

 private slots:
  /* Appearance buttons */
  void resizePanel();
  void showHidePanels();
  void showAll();
  void hideAll();
  void showControlPanel();
  void hideControlPanel();
  void showSettings();
  void hideSettings();
  void showExport();
  void hideExport();
  /* Use buttons */
  void findFile();
  void loadFile();
  void resetModel();
  void closeModel();
  /* Control panel */
  void rescaleMinus();
  void rescalePlus();
  void shiftXMinus();
  void shiftXPlus();
  void shiftYMinus();
  void shiftYPlus();
  void shiftZMinus();
  void shiftZPlus();
  void rotateXMinus();
  void rotateXPlus();
  void rotateYMinus();
  void rotateYPlus();
  void rotateZMinus();
  void rotateZPlus();
  /* Settings panel */
  void setDefaultSettings();
  void loadSettings();
  void saveSettings();
  void newBackgroundColor();
  void newDotColor();
  void newLineColor();
  void moveCameraZChanged(int value);
  void cameraShiftZChanged(int value);
  void showAxisChanged(int value);
  void projectionChanged(int value);
  void dotTypeChanged(int value);
  void lineTypeChanged(int value);
  void lineStippleChanged(int value);
  void dotSizeChanged(double value);
  void lineWidthChanged(double value);
  /* Export section */
  void exportImage();
  void exportGifStart();
  void exportGifEnd();
  /* Misc slots */
  void renewScaleLabel();

 private:
  Ui::MainWindow* ui;
  QSettings* gl_settings_;
  QElapsedTimer load_timer_;
  QTimer f_timer_;
  QGifImage* gif_ = NULL;
  int miliseconds_ = 0;

  const QFont FONT_COMMON = QFont("Anta", 10);
  const QFont FONT_BUTTON = QFont("Anta", 10);
  const QFont FONT_LABEL = QFont("Anta", 11);
  const QFont FONT_COMMON_RETINA = QFont("Anta", 13);
  const QFont FONT_BUTTON_RETINA = QFont("Anta", 14);
  const QFont FONT_LABEL_RETINA = QFont("Anta", 14);

  static const size_t MAX_NUMBER_CHARS = 25;

  static const int GIF_TIMEOUT_MSEC = 1000 / 10;
  static const int GIF_FRAME_APPEND_DELAY_MSEC = 100;
  static const int GIF_WIDTH_RES = 640;
  static const int GIF_HEIGHT_RES = 480;
  static const int GIF_STEP_MSEC = 100;
  static const int GIF_ENDTIME_MSEC = 5000;

  void connectSignals();
  void setInitialState();
  void setUiSettings();
  void setFonts();
  void setStyle();

  void clearFileInfo();
  void setFileInfo();
  size_t getFileSize();
  std::string getFileSizeString();

  QString chooseDirectory();
  QString currentDateTime();

  void moveView(bool fullscreen = false);

  void saveGif();

  void showMessage(QString text, QString color);

  int sumWidgetHeights();
  static const int PANEL_WIDGETS_NUM = 4;

  static const int MESSAGE_MARGIN = 10;
  static const int SYMBOL_PIXELS = 9;
};

#endif  // MAINWINDOW_H
