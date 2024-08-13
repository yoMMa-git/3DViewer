#ifndef S21_MODEL_H
#define S21_MODEL_H

#include <algorithm>
#include <cstring>
#include <fstream>
#include <sstream>
#include <thread>
#include <vector>

#include "s21_transformation.h"

/* Template Method pattern */
/* Prototype pattern with factory class */
namespace s21 {

/* Geometry vertex */
struct GVertex : public Vertex {
  double w = 1.0;
};

/* Indices of two vertices making a straight line */
struct Edge {
  int a, b;
};

class Object;
class Skeleton;

class PrototypeFactory {
 public:
  PrototypeFactory() {}
  ~PrototypeFactory() {}
  static Object* createSkeleton();
};

class Object {
 public:
  virtual ~Object() {}
  /* Get methods */
  double getMaxZ() const noexcept;
  size_t getCurrentLine() const noexcept;
  size_t getVerticesSize() const noexcept;
  GVertex* getVerticesData() noexcept;
  virtual size_t getFacesSize() const noexcept = 0;
  virtual void* getFacesData() noexcept = 0;

  /* Drop all variables to default */
  void resetData() noexcept;
  /* Parse methods */
  void parse(std::string file_name);
  void parse(std::ifstream& input);
  void parse(std::stringstream& input);
  /* Vertices data transformations */
  void transformData(Action action, Axis axis, double value);
  void centralizeData();
  void normalizeData(double coef = 1.0);
  /* Faces data transformations. */
  virtual void compactData() = 0;

 protected:
  std::vector<GVertex> vertices{};
  /* Max Z coordinate (sign dependent). For adjusting user camera. */
  double max_z_ = 0.0;
  size_t line_index_ = 0;
  GVertex buffer_vertex_{};
  double min_x_ = 0.0, max_x_ = 0.0, min_y_ = 0.0, max_y_ = 0.0, min_z_ = 0.0;
  int concurrent_threads_ = std::thread::hardware_concurrency();

  virtual Object* clone() = 0;

  /* Coordinates element, starts with 'v', 'vt', 'vn' or 'vp'. */
  virtual void parseVertex(std::string&) = 0;
  /* Polygonal face element, starts with 'f' */
  virtual void parseFace(std::string&) = 0;

  /* Misc */
  virtual void resetChildParameters() noexcept = 0;
  void setMaxZ(double value) noexcept;
  bool validateIndex(int index) const noexcept;
  void transformIndex(int& id) const noexcept;
  void findMinMaxValues(Axis axis) noexcept;
  void centralizeAxis(Axis axis);
  void centralizeAll();
  void transformDataWrapper(Action action, Axis axis, double value);
  /* Created for optimization of centralize function */
  void transformData(std::vector<std::pair<Transformation*, double>>& methods);
};

/* Parsing only geometry vertices and lines between them in optimal way. */
class Skeleton : virtual public Object {
 public:
  Skeleton() {}
  ~Skeleton() {}

  friend class PrototypeFactory;

  size_t getFacesSize() const noexcept;
  void* getFacesData() noexcept;
  void compactData();

 private:
  std::vector<Edge> edges;

  Object* clone();

  void resetChildParameters() noexcept;
  void deleteDuplicateEdges();
  void parseVertex(std::string& str);
  void parseFace(std::string& str);
  void pushEdge(int a, int b);
  bool edgesIsEqual(const Edge& first, const Edge& second) const noexcept;
  static bool compareEdges(const Edge& first, const Edge& second) noexcept;
};

}  // namespace s21

#endif  // S21_MODEL_H
