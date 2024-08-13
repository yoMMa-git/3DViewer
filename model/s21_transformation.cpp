#include "s21_transformation.h"

namespace s21 {

Transformation* Transformation::createTransformation(Action action, Axis axis) {
  Transformation* ret;
  switch (action) {
    case SCALE:
      if (axis == ALL)
        ret = new ScaleAll();
      else if (axis == X)
        ret = new ScaleX();
      else if (axis == Y)
        ret = new ScaleY();
      else if (axis == Z)
        ret = new ScaleZ();
      else
        assert(false);
      break;
    case SHIFT:
      if (axis == X)
        ret = new ShiftX();
      else if (axis == Y)
        ret = new ShiftY();
      else if (axis == Z)
        ret = new ShiftZ();
      else
        assert(false);
      break;
    case ROTATE:
      if (axis == X)
        ret = new RotateX();
      else if (axis == Y)
        ret = new RotateY();
      else if (axis == Z)
        ret = new RotateZ();
      else
        assert(false);
      break;
    default:
      assert(false);
      break;
  }
  return ret;
}

void ScaleAll::transform(Vertex& v, double value) const noexcept {
  if (value != 0) {
    v.x *= value;
    v.y *= value;
    v.z *= value;
  }
}

void ScaleX::transform(Vertex& v, double value) const noexcept {
  if (value != 0) {
    v.x *= value;
  }
}

void ScaleY::transform(Vertex& v, double value) const noexcept {
  if (value != 0) {
    v.y *= value;
  }
}

void ScaleZ::transform(Vertex& v, double value) const noexcept {
  if (value != 0) {
    v.z *= value;
  }
}

void ShiftX::transform(Vertex& v, double value) const noexcept { v.x += value; }
void ShiftY::transform(Vertex& v, double value) const noexcept { v.y += value; }
void ShiftZ::transform(Vertex& v, double value) const noexcept { v.z += value; }

void RotateX::transform(Vertex& v, double value) const noexcept {
  double y = v.y, z = v.z;
  v.y = y * std::cos(value) - z * std::sin(value);
  v.z = y * std::sin(value) + z * std::cos(value);
}
void RotateY::transform(Vertex& v, double value) const noexcept {
  double x = v.x, z = v.z;
  v.x = x * std::cos(value) + z * std::sin(value);
  v.z = -x * std::sin(value) + z * std::cos(value);
}
void RotateZ::transform(Vertex& v, double value) const noexcept {
  double x = v.x, y = v.y;
  v.x = x * std::cos(value) - y * std::sin(value);
  v.y = x * std::sin(value) + y * std::cos(value);
}

}  // namespace s21
