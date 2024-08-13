#ifndef OPENGLWIDGET_H
#define OPENGLWIDGET_H
#define GL_SILENCE_DEPRECATION

#include <QColor>
#include <QMouseEvent>
#include <QOpenGLFunctions>
#include <QOpenGLWidget>
#include <QWheelEvent>
#include <QWidget>

#include "../controller/s21_controller.h"
#include "openglsettings.h"

namespace Ui {
class OpenGLWidget;
}

class OpenGLWidget : public QOpenGLWidget, public QOpenGLFunctions {
  Q_OBJECT

 public:
  explicit OpenGLWidget(QWidget* parent = nullptr);
  ~OpenGLWidget();

  OpenGLSettings settings_;

  void loadFile(std::string file_name);
  void rescale(double value);
  void shiftX(double value);
  void shiftY(double value);
  void shiftZ(double value);
  void rotateX(double value);
  void rotateY(double value);
  void rotateZ(double value);

  void reinstateData();
  void closeObject() noexcept;

  void setWidgetLeftShiftX(int value);
  void setWidgetRightShiftX(int value);

  size_t getVerticesNumber() const noexcept;
  size_t getEdgesNumber() const noexcept;
  double getScaleValue() const noexcept;
  bool checkScaleValue(double scale_mult) const noexcept;

 protected:
  void initializeGL() override;
  void paintGL() override;
  void resizeGL(int w, int h) override;

 private:
  Ui::OpenGLWidget* ui;
  s21::Controller data;
  double ratio_ = 1.0;
  int widget_x_left_shift_ = 0;
  int widget_x_right_shift_ = 0;
  double x_left_ratio_ = 1.0, x_right_ratio_ = 1.0, y_ratio_ = 1.0;

  static constexpr double MAX_SCALE = 400.0;
  static constexpr double MIN_SCALE = 0.01;
  static constexpr QColor COLOR_AXIS = QColor(255, 210, 128);

  static constexpr double FAR_POINT = 1000.0;
  static constexpr double NEAR_POINT = 1.0;

  void drawModel();
  void drawAxes();
  void initializeState() noexcept;
  void setRatio() noexcept;

  /* Mouse control section */
  double x_rot_ = 0.0, y_rot_ = 0.0, rotation_freq_ = ROTATION_FREQUENCY_3;
  QPoint m_pos_;

  static const size_t VERTICES_FREQLIMIT_1 = 1000000;
  static const size_t VERTICES_FREQLIMIT_2 = 300000;
  static constexpr double ROTATION_FREQUENCY_1 = 0.1;
  static constexpr double ROTATION_FREQUENCY_2 = 0.01;
  static constexpr double ROTATION_FREQUENCY_3 = 0.001;

  void mousePressEvent(QMouseEvent* move) override;
  void mouseMoveEvent(QMouseEvent* move) override;
  void wheelEvent(QWheelEvent* move) override;
  void calculateRotationSpeed() noexcept;

 signals:
  void scaleChanged();
};

#endif  // OPENGLWIDGET_H
