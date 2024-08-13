#include "s21_model.h"

namespace s21 {

/* Creation begin */
Object* PrototypeFactory::createSkeleton() {
  static Skeleton prototype;
  return prototype.clone();
}
Object* Skeleton::clone() { return new Skeleton(*this); };
/* Creation end */

/* Object begin */
/* Interface begin */
double Object::getMaxZ() const noexcept { return max_z_; }
size_t Object::getCurrentLine() const noexcept { return line_index_; }
size_t Object::getVerticesSize() const noexcept { return vertices.size(); }
GVertex* Object::getVerticesData() noexcept { return vertices.data(); }

void Object::resetData() noexcept {
  vertices.clear();
  max_z_ = 0.0;
  resetChildParameters();
}

void Object::parse(std::string file_name) {
  resetData();
  line_index_ = 0;
  std::ifstream file(file_name);
  if (file.is_open()) {
    parse(file);
    file.close();
  } else {
    throw std::invalid_argument("Couldn't open file.");
  }
}

void Object::parse(std::ifstream& input) {
  std::stringstream ss;
  ss << input.rdbuf();
  parse(ss);
}

void Object::parse(std::stringstream& input) {
  line_index_ = 0;
  for (std::string line; std::getline(input, line); ++line_index_) {
    if (line.size() < 2 || line[1] != ' ') continue;
    if (line[0] == 'v')
      parseVertex(line);
    else if (line[0] == 'f')
      parseFace(line);
  }
  if (vertices.size() == 0) {
    resetData();
    throw std::invalid_argument("File contains no Object.");
  }
}

void Object::transformData(Action action, Axis axis, double value) {
  Transformation* method = Transformation::createTransformation(action, axis);
  if (action == SHIFT && (axis == X || axis == Y)) {
    for (GVertex& i : vertices) {
      method->transform(i, value);
    }
  } else {
    max_z_ = 0.0;
    for (GVertex& i : vertices) {
      method->transform(i, value);
      setMaxZ(i.z);
    }
  }
  delete method;
}

void Object::centralizeData() {
  if (vertices.size() > 0) {
    min_x_ = vertices[0].x, min_y_ = vertices[0].y, min_z_ = vertices[0].z,
    max_x_ = vertices[0].x, max_y_ = vertices[0].y, max_z_ = vertices[0].z;
    if (concurrent_threads_ > 2) {
      std::thread thread_1(&Object::centralizeAxis, this, X);
      std::thread thread_2(&Object::centralizeAxis, this, Y);
      std::thread thread_3(&Object::centralizeAxis, this, Z);
      thread_1.join();
      thread_2.join();
      thread_3.join();
    } else {
      centralizeAll();
    }
  }
}

void Object::normalizeData(double coef) {
  double abs_max = 0.0, value = 0.0;
  for (GVertex i : vertices) {
    if (std::fabs(i.x) > abs_max) abs_max = std::fabs(i.x);
    if (std::fabs(i.y) > abs_max) abs_max = std::fabs(i.y);
    if (std::fabs(i.z) > abs_max) abs_max = std::fabs(i.z);
  }
  value = coef / abs_max;
  if (concurrent_threads_ > 1) {
    std::thread thread_1(&Object::transformDataWrapper, this, SCALE, X, value);
    std::thread thread_2(&Object::transformDataWrapper, this, SCALE, Y, value);
    thread_1.join();
    thread_2.join();
    transformDataWrapper(SCALE, Z, value);
  } else {
    transformData(SCALE, ALL, value);
  }
}
/* Interface end */

/* Misc begin */
void Object::centralizeAxis(Axis axis) {
  findMinMaxValues(axis);
  double shift = 0.0;
  if (axis == X) {
    shift = -(min_x_ + max_x_) / 2.0;
    min_x_ += shift;
    max_x_ += shift;
  } else if (axis == Y) {
    shift = -(min_y_ + max_y_) / 2.0;
    min_y_ += shift;
    max_y_ += shift;
  } else if (axis == Z) {
    shift = -(min_z_ + max_z_) / 2.0;
    min_z_ += shift;
    max_z_ += shift;
  }
  transformData(SHIFT, axis, shift);
}

void Object::centralizeAll() {
  if (vertices.size() > 0) {
    findMinMaxValues(ALL);
    std::vector<std::pair<Transformation*, double>> methods;
    methods.push_back(std::pair(Transformation::createTransformation(SHIFT, X),
                                -(min_x_ + max_x_) / 2.0));
    methods.push_back(std::pair(Transformation::createTransformation(SHIFT, Y),
                                -(min_y_ + max_y_) / 2.0));
    methods.push_back(std::pair(Transformation::createTransformation(SHIFT, Z),
                                -(min_z_ + max_z_) / 2.0));
    transformData(methods);
    for (auto i : methods) {
      delete i.first;
    }
  }
}

void Object::findMinMaxValues(Axis axis) noexcept {
  switch (axis) {
    case X:
      for (GVertex i : vertices) {
        if (i.x < min_x_) min_x_ = i.x;
        if (i.x > max_x_) max_x_ = i.x;
      }
      break;
    case Y:
      for (GVertex i : vertices) {
        if (i.y < min_y_) min_y_ = i.y;
        if (i.y > max_y_) max_y_ = i.y;
      }
      break;
    case Z:
      for (GVertex i : vertices) {
        if (i.z < min_z_) min_z_ = i.z;
        if (i.z > max_z_) max_z_ = i.z;
      }
      break;
    default:
      for (GVertex i : vertices) {
        if (i.x < min_x_) min_x_ = i.x;
        if (i.x > max_x_) max_x_ = i.x;
        if (i.y < min_y_) min_y_ = i.y;
        if (i.y > max_y_) max_y_ = i.y;
        if (i.z < min_z_) min_z_ = i.z;
        if (i.z > max_z_) max_z_ = i.z;
      }
      break;
  }
}

void Object::transformDataWrapper(Action action, Axis axis, double value) {
  transformData(action, axis, value);
}

void Object::transformData(
    std::vector<std::pair<Transformation*, double>>& methods) {
  max_z_ = 0.0;
  for (GVertex& i : vertices) {
    for (std::pair<Transformation*, double> j : methods) {
      j.first->transform(i, j.second);
    }
    setMaxZ(i.z);
  }
}

void Object::setMaxZ(double value) noexcept {
  if (value > max_z_) max_z_ = value;
}

bool Object::validateIndex(int index) const noexcept {
  return index < 0 || index >= static_cast<int>(vertices.size()) ? false : true;
}

void Object::transformIndex(int& id) const noexcept {
  id = id < 0 ? static_cast<int>(vertices.size()) + id : id - 1;
}
/* Misc end */
/* Object end */

/* Skeleton object begin */
/* Interface begin (Skeleton) */
size_t Skeleton::getFacesSize() const noexcept { return edges.size(); }
void* Skeleton::getFacesData() noexcept { return edges.data(); }

void Skeleton::compactData() {
  std::sort(edges.begin(), edges.end(), compareEdges);
  deleteDuplicateEdges();
}
/* Interface end (Skeleton) */

/* Misc begin (SKeleton) */
void Skeleton::resetChildParameters() noexcept { edges.clear(); }

void Skeleton::parseVertex(std::string& str) {
  int sscanf_ret =
      std::sscanf(str.c_str(), "v %lf %lf %lf %lf", &buffer_vertex_.x,
                  &buffer_vertex_.y, &buffer_vertex_.z, &buffer_vertex_.w);
  if (sscanf_ret < 3) {
    resetData();
    throw std::invalid_argument(
        "Incomplete coordinate (line: " + std::to_string(line_index_) + ").");
  } else {
    vertices.push_back(buffer_vertex_);
    buffer_vertex_.w = 1.0;
    setMaxZ(buffer_vertex_.z);
  }
}

void Skeleton::parseFace(std::string& str) {
  std::istringstream ss(str);
  std::string node;
  ss >> node;
  int first, second, last;
  ss >> node;
  if (ss.fail()) return;
  if (std::sscanf(node.c_str(), "%d", &first) != 1) return;
  transformIndex(first);
  last = first;
  while (ss >> node) {
    if (std::sscanf(node.c_str(), "%d", &second) != 1) return;
    transformIndex(second);
    if (validateIndex(first) == false || validateIndex(second) == false) {
      resetData();
      throw std::invalid_argument(
          "Invalid index (line: " + std::to_string(line_index_) + ").");
    }
    if (first != second) {
      pushEdge(first, second);
      first = second;
    }
  }
  if (first != last) pushEdge(first, last);
}

void Skeleton::pushEdge(int a, int b) {
  edges.push_back(a < b ? Edge{a, b} : Edge{b, a});
}

bool Skeleton::compareEdges(const Edge& first, const Edge& second) noexcept {
  if (first.a == second.a) return first.b < second.b;
  return first.a < second.a;
}

bool Skeleton::edgesIsEqual(const Edge& first,
                            const Edge& second) const noexcept {
  return first.a == second.a && first.b == second.b;
}

void Skeleton::deleteDuplicateEdges() {
  std::vector<Edge> buffer;
  buffer.reserve(edges.capacity());
  for (std::vector<Edge>::iterator iter = edges.begin();
       edges.size() > 1 && iter < edges.end(); ++iter) {
    if (iter + 1 == edges.end() || edgesIsEqual(*iter, *(iter + 1)) == false)
      buffer.push_back(*iter);
  }
  edges.swap(buffer);
}
/* Misc end (SKeleton) */
/* Skeleton object end */

}  // namespace s21
