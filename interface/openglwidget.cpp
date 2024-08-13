#include "openglwidget.h"

#include "ui_openglwidget.h"

OpenGLWidget::OpenGLWidget(QWidget* parent)
    : QOpenGLWidget{parent}, ui(new Ui::OpenGLWidget) {
  ui->setupUi(this);
}

OpenGLWidget::~OpenGLWidget() { delete ui; }

void OpenGLWidget::loadFile(std::string file_name) {
  data.loadData(file_name);
  initializeState();
}

void OpenGLWidget::initializeState() noexcept {
  if (data.getVerticesSize() > 0) {
    calculateRotationSpeed();
  }
}

void OpenGLWidget::reinstateData() { data.reinstateData(); }

void OpenGLWidget::closeObject() noexcept { data.closeObject(); }

size_t OpenGLWidget::getVerticesNumber() const noexcept {
  return data.getVerticesSize();
}

size_t OpenGLWidget::getEdgesNumber() const noexcept {
  return data.getEdgesSize();
}

double OpenGLWidget::getScaleValue() const noexcept { return data.getScale(); }

bool OpenGLWidget::checkScaleValue(double scale_mult) const noexcept {
  scale_mult *= data.getScale();
  return scale_mult > MIN_SCALE && scale_mult < MAX_SCALE;
}

void OpenGLWidget::setWidgetLeftShiftX(int value) {
  widget_x_left_shift_ = value;
  setRatio();
  update();
}

void OpenGLWidget::setWidgetRightShiftX(int value) {
  widget_x_right_shift_ = value;
  setRatio();
  update();
}

void OpenGLWidget::initializeGL() {
  initializeOpenGLFunctions();
  glEnable(GL_DEPTH_TEST);
}

void OpenGLWidget::resizeGL(int w, int h) {
  glViewport(0, 0, w, h);
  ratio_ = static_cast<double>(w) / static_cast<double>(h);
  setRatio();
}

void OpenGLWidget::paintGL() {
  glClearColor(settings_.getColorBackground().redF(),
               settings_.getColorBackground().greenF(),
               settings_.getColorBackground().blueF(),
               settings_.getColorBackground().alphaF());
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
  glEnable(GL_BLEND);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  double shift = data.getScale() * settings_.getCameraShiftZ();
  if (settings_.getMoveCameraZ() == true && shift < data.getMaxZ()) {
    shift = data.getMaxZ();
  }
  if (settings_.getProjection() == OpenGLSettings::PERSPECTIVE) {
    glFrustum(-1.0 * ratio_ * x_left_ratio_, 1.0 * ratio_ * x_right_ratio_,
              -1.0 * y_ratio_, 1.0 * y_ratio_, NEAR_POINT * shift,
              FAR_POINT * shift);
  } else if (settings_.getProjection() == OpenGLSettings::PARALLEL) {
    glOrtho(-2.0 * ratio_ * x_left_ratio_, 2.0 * ratio_ * x_right_ratio_,
            -2.0 * y_ratio_, 2.0 * y_ratio_, NEAR_POINT * shift,
            FAR_POINT * shift);
  }
  glTranslatef(0, 0, -2.0 * shift);
  if (settings_.getShowAxis() == true) drawAxes();
  drawModel();
  glDisable(GL_BLEND);
}

void OpenGLWidget::drawModel() {
  glVertexPointer(3, GL_DOUBLE, sizeof(s21::GVertex), data.getVertices());
  glEnableClientState(GL_VERTEX_ARRAY);
  glPointSize(settings_.getDotSize());
  glColor4f(settings_.getColorDot().redF(), settings_.getColorDot().greenF(),
            settings_.getColorDot().blueF(), settings_.getColorDot().alphaF());
  if (settings_.getDotType() == OpenGLSettings::CIRCLE) {
    glEnable(GL_POINT_SMOOTH);
    glDrawArrays(GL_POINTS, 0, data.getVerticesSize());
    glDisable(GL_POINT_SMOOTH);
  } else if (settings_.getDotType() == OpenGLSettings::SQUARE) {
    glDrawArrays(GL_POINTS, 0, data.getVerticesSize());
  }

  glLineWidth(settings_.getLineWidth());
  glColor4f(settings_.getColorLine().redF(), settings_.getColorLine().greenF(),
            settings_.getColorLine().blueF(),
            settings_.getColorLine().alphaF());
  if (settings_.getLineType() == OpenGLSettings::DOTTED) {
    glLineStipple(settings_.getStippleFactor(), settings_.getStipplePattern());
    glEnable(GL_LINE_STIPPLE);
    glDrawElements(GL_LINES, data.getEdgesSize() * 2, GL_UNSIGNED_INT,
                   data.getEdges());
    glDisable(GL_LINE_STIPPLE);
  } else if (settings_.getLineType() == OpenGLSettings::SOLID) {
    glDrawElements(GL_LINES, data.getEdgesSize() * 2, GL_UNSIGNED_INT,
                   data.getEdges());
  }
  glDisableClientState(GL_VERTEX_ARRAY);
}

void OpenGLWidget::drawAxes() {
  double dots[] = {4.0 * ratio_, 0.0, 0.0, -4.0 * ratio_, 0.0, 0.0, 0.0,
                   4.0 * ratio_, 0.0, 0.0, -4.0 * ratio_, 0.0, 0.0, 0.0,
                   2.0 * ratio_, 0.0, 0.0, -2.0 * ratio_};
  int axis[] = {0, 1, 2, 3, 4, 5};
  glVertexPointer(3, GL_DOUBLE, 0, dots);
  glEnableClientState(GL_VERTEX_ARRAY);
  glLineWidth(2.0);
  glColor3f(COLOR_AXIS.redF(), COLOR_AXIS.greenF(), COLOR_AXIS.blueF());
  glDrawElements(GL_LINES, 6, GL_UNSIGNED_INT, axis);
  glDisableClientState(GL_VERTEX_ARRAY);
}

void OpenGLWidget::rescale(double value) { data.rescale(value); }
void OpenGLWidget::shiftX(double value) { data.shiftX(value); }
void OpenGLWidget::shiftY(double value) { data.shiftY(value); }
void OpenGLWidget::shiftZ(double value) { data.shiftZ(value); }
void OpenGLWidget::rotateX(double value) { data.rotateX(value); }
void OpenGLWidget::rotateY(double value) { data.rotateY(value); }
void OpenGLWidget::rotateZ(double value) { data.rotateZ(value); }

void OpenGLWidget::mousePressEvent(QMouseEvent* move) { m_pos_ = move->pos(); }

void OpenGLWidget::mouseMoveEvent(QMouseEvent* move) {
  x_rot_ += 0.0002 / M_PI * (move->pos().y() - m_pos_.y()),
      y_rot_ += 0.0002 / M_PI * (move->pos().x() - m_pos_.x());
  if (fabs(x_rot_) > rotation_freq_ || fabs(y_rot_) > rotation_freq_) {
    rotateX(x_rot_);
    rotateY(y_rot_);
    x_rot_ = 0.0;
    y_rot_ = 0.0;
    update();
  }
}

void OpenGLWidget::wheelEvent(QWheelEvent* move) {
  double step = 1.0 + (move->angleDelta().y() % 180) / 180.0;
  if (checkScaleValue(step)) {
    data.rescale(step);
    update();
    emit scaleChanged();
  }
}

void OpenGLWidget::calculateRotationSpeed() noexcept {
  if (data.getVerticesSize() > VERTICES_FREQLIMIT_1) {
    rotation_freq_ = ROTATION_FREQUENCY_1;
  } else if (data.getVerticesSize() > VERTICES_FREQLIMIT_2) {
    rotation_freq_ = ROTATION_FREQUENCY_2;
  } else {
    rotation_freq_ = ROTATION_FREQUENCY_3;
  }
}

void OpenGLWidget::setRatio() noexcept {
  x_left_ratio_ = 1.0 + static_cast<double>(widget_x_left_shift_) /
                            static_cast<double>(width()) * 2;
  x_right_ratio_ = 1.0 + static_cast<double>(widget_x_right_shift_) /
                             static_cast<double>(width()) * 2;
  y_ratio_ =
      1.0 +
      static_cast<double>(widget_x_left_shift_) / static_cast<double>(width()) +
      static_cast<double>(widget_x_right_shift_) / static_cast<double>(width());
}
