#ifndef S21_CONTROLLER_H
#define S21_CONTROLLER_H

#include <thread>

#include "../model/s21_model.h"

/* Facade pattern */
namespace s21 {

class Controller {
 public:
  Controller();
  ~Controller();

  void loadData(std::string file_name);
  void reinstateData();
  void closeObject() noexcept;

  void rescale(double value);
  void rescaleX(double value);
  void rescaleY(double value);
  void rescaleZ(double value);
  void shiftX(double value);
  void shiftY(double value);
  void shiftZ(double value);
  void rotateX(double value);
  void rotateY(double value);
  void rotateZ(double value);

  size_t getVerticesSize() const noexcept;
  size_t getEdgesSize() const noexcept;
  GVertex* getVertices() noexcept;
  Edge* getEdges() noexcept;
  size_t getCurrentLine() const noexcept;
  double getMaxZ() const noexcept;
  double getScale() const noexcept;

 private:
  Object *object, *saved;
  double scale_ = 1.0;
  int concurrent_threads_ = std::thread::hardware_concurrency();

  void processVertices();
  void processFaces();
  /* Rescaling using multithreading */
  void rescaleMT(double value);
};

}  // namespace s21

#endif  // S21_CONTROLLER_H
