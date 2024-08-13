#include "openglsettings.h"

OpenGLSettings::OpenGLSettings() { setDefault(); }

void OpenGLSettings::setColorDot(QColor color) noexcept { color_dot_ = color; }
void OpenGLSettings::setColorLine(QColor color) noexcept {
  color_line_ = color;
}
void OpenGLSettings::setColorBackground(QColor color) noexcept {
  color_background_ = color;
}
void OpenGLSettings::setProjection(ProjectionType value) noexcept {
  projection_ = value;
}
void OpenGLSettings::setDotType(DotType value) noexcept { dot_type_ = value; }
void OpenGLSettings::setLineType(LineType value) noexcept {
  line_type_ = value;
}
void OpenGLSettings::setLineWidth(float value) noexcept { line_width_ = value; }
void OpenGLSettings::setDotSize(float value) noexcept { dot_size_ = value; }
void OpenGLSettings::setShowAxis(bool flag) noexcept { show_axis_ = flag; }
void OpenGLSettings::setMoveCameraZ(bool flag) noexcept {
  move_camera_z_ = flag;
}
void OpenGLSettings::setCameraShiftZ(double value) noexcept {
  camera_shift_z_ = value;
}
void OpenGLSettings::setStippleType(int stipple) noexcept {
  if (stipple >= 0 && stipple < STIPPLE_TYPES) {
    stipple_type_ = stipple;
    line_stipple_.factor_ = stipple_patterns[stipple].factor_;
    line_stipple_.pattern_ = stipple_patterns[stipple].pattern_;
  }
}

QColor OpenGLSettings::getColorDot() const noexcept { return color_dot_; }
QColor OpenGLSettings::getColorLine() const noexcept { return color_line_; }
QColor OpenGLSettings::getColorBackground() const noexcept {
  return color_background_;
}
OpenGLSettings::ProjectionType OpenGLSettings::getProjection() const noexcept {
  return projection_;
}
OpenGLSettings::DotType OpenGLSettings::getDotType() const noexcept {
  return dot_type_;
}
OpenGLSettings::LineType OpenGLSettings::getLineType() const noexcept {
  return line_type_;
}
float OpenGLSettings::getLineWidth() const noexcept { return line_width_; }
float OpenGLSettings::getDotSize() const noexcept { return dot_size_; }
bool OpenGLSettings::getShowAxis() const noexcept { return show_axis_; }
bool OpenGLSettings::getMoveCameraZ() const noexcept { return move_camera_z_; }
int OpenGLSettings::getStippleType() const noexcept { return stipple_type_; }
GLint OpenGLSettings::getStippleFactor() const noexcept {
  return line_stipple_.factor_;
}
GLushort OpenGLSettings::getStipplePattern() const noexcept {
  return line_stipple_.pattern_;
}
double OpenGLSettings::getCameraShiftZ() const noexcept {
  return camera_shift_z_;
}
