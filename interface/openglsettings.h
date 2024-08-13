#ifndef OPENGLSETTINGS_H
#define OPENGLSETTINGS_H

#include <QColor>
#include <QOpenGLFunctions>

#define STIPPLE_TYPES 8

class OpenGLSettings {
 public:
  OpenGLSettings();

  enum ProjectionType { PERSPECTIVE, PARALLEL };
  enum DotType { NONE, CIRCLE, SQUARE };
  enum LineType { SOLID, DOTTED };

  static constexpr QColor DEFAULT_COLOR_DOT = QColor(255, 255, 255);
  static constexpr QColor DEFAULT_COLOR_LINE = QColor(255, 255, 255);
  static constexpr QColor DEFAULT_COLOR_BACKGROUND = QColor(21, 22, 30);
  static const ProjectionType DEFAULT_PROJECTION = PERSPECTIVE;
  static const DotType DEFAULT_DOT_TYPE = NONE;
  static const LineType DEFAULT_LINE_TYPE = SOLID;
  static constexpr float DEFAULT_DOT_SIZE = 1.0f;
  static constexpr float DEFAULT_LINE_WIDTH = 1.0f;
  static const bool DEFAULT_SHOW_AXIS = false;
  static const bool DEFAULT_MOVE_CAMERA_Z = false;
  static constexpr double DEFAULT_CAMERA_SHIFT_Z = 2.0;
  static const int DEFAULT_STIPPLE_TYPE = 0;

  void setColorDot(QColor color) noexcept;
  void setColorLine(QColor color) noexcept;
  void setColorBackground(QColor color) noexcept;
  void setProjection(ProjectionType value) noexcept;
  void setDotType(DotType value) noexcept;
  void setLineType(LineType value) noexcept;
  void setLineWidth(float value) noexcept;
  void setDotSize(float value) noexcept;
  void setShowAxis(bool flag) noexcept;
  void setMoveCameraZ(bool flag) noexcept;
  void setCameraShiftZ(double value) noexcept;
  void setStippleType(int stipple) noexcept;

  QColor getColorDot() const noexcept;
  QColor getColorLine() const noexcept;
  QColor getColorBackground() const noexcept;
  ProjectionType getProjection() const noexcept;
  DotType getDotType() const noexcept;
  LineType getLineType() const noexcept;
  float getLineWidth() const noexcept;
  float getDotSize() const noexcept;
  bool getShowAxis() const noexcept;
  bool getMoveCameraZ() const noexcept;
  double getCameraShiftZ() const noexcept;
  int getStippleType() const noexcept;
  GLint getStippleFactor() const noexcept;
  GLushort getStipplePattern() const noexcept;

  void setDefault() noexcept {
    color_dot_ = DEFAULT_COLOR_DOT;
    color_line_ = DEFAULT_COLOR_LINE;
    color_background_ = DEFAULT_COLOR_BACKGROUND;
    projection_ = DEFAULT_PROJECTION;
    dot_type_ = DEFAULT_DOT_TYPE;
    line_type_ = DEFAULT_LINE_TYPE;
    dot_size_ = DEFAULT_DOT_SIZE;
    line_width_ = DEFAULT_LINE_WIDTH;
    show_axis_ = DEFAULT_SHOW_AXIS;
    move_camera_z_ = DEFAULT_MOVE_CAMERA_Z;
    camera_shift_z_ = DEFAULT_CAMERA_SHIFT_Z;
    setStippleType(DEFAULT_STIPPLE_TYPE);
  }

 private:
  struct LineStipple {
    GLint factor_;
    GLushort pattern_;
  };

  const struct LineStipple stipple_patterns[STIPPLE_TYPES] = {
      {1, 0x00FF}, {2, 0x00FF}, {1, 0x0C0F}, {3, 0x0C0F},
      {1, 0xAAAA}, {2, 0xAAAA}, {3, 0xAAAA}, {4, 0xAAAA}};

  QColor color_dot_;
  QColor color_line_;
  QColor color_background_;
  ProjectionType projection_;
  DotType dot_type_;
  LineType line_type_;
  float dot_size_;
  float line_width_;
  bool show_axis_;
  bool move_camera_z_;
  double camera_shift_z_;
  int stipple_type_;
  LineStipple line_stipple_;
};

#endif  // OPENGLSETTINGS_H
