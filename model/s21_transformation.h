#ifndef S21_TRANSFORMATION_H
#define S21_TRANSFORMATION_H

#include <cassert>
#include <cmath>

/* Factory method with algorithm template */
namespace s21 {

enum Axis { X, Y, Z, ALL };
enum Action { SCALE, SHIFT, ROTATE };

struct Vertex {
  double x, y, z;
};

class Transformation {
 public:
  Transformation() {}
  virtual ~Transformation() {}

  static Transformation* createTransformation(Action action, Axis axis);
  virtual void transform(Vertex&, double) const noexcept = 0;
};

class ScaleAll : virtual public Transformation {
 public:
  ScaleAll() {}
  ~ScaleAll() {}
  void transform(Vertex& v, double value) const noexcept;
};

class ScaleX : virtual public Transformation {
 public:
  ScaleX() {}
  ~ScaleX() {}
  void transform(Vertex& v, double value) const noexcept;
};

class ScaleY : virtual public Transformation {
 public:
  ScaleY() {}
  ~ScaleY() {}
  void transform(Vertex& v, double value) const noexcept;
};

class ScaleZ : virtual public Transformation {
 public:
  ScaleZ() {}
  ~ScaleZ() {}
  void transform(Vertex& v, double value) const noexcept;
};

class ShiftX : virtual public Transformation {
 public:
  ShiftX() {}
  ~ShiftX() {}
  void transform(Vertex& v, double value) const noexcept;
};

class ShiftY : virtual public Transformation {
 public:
  ShiftY() {}
  ~ShiftY() {}
  void transform(Vertex& v, double value) const noexcept;
};

class ShiftZ : virtual public Transformation {
 public:
  ShiftZ() {}
  ~ShiftZ() {}
  void transform(Vertex& v, double value) const noexcept;
};

class RotateX : virtual public Transformation {
 public:
  RotateX() {}
  ~RotateX() {}
  void transform(Vertex& v, double value) const noexcept;
};

class RotateY : virtual public Transformation {
 public:
  RotateY() {}
  ~RotateY() {}
  void transform(Vertex& v, double value) const noexcept;
};

class RotateZ : virtual public Transformation {
 public:
  RotateZ() {}
  ~RotateZ() {}
  void transform(Vertex& v, double value) const noexcept;
};

}  // namespace s21

#endif  // S21_TRANSFORMATION_H
