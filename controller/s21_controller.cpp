#include "s21_controller.h"

namespace s21 {

Controller::Controller() {
  object = PrototypeFactory::createSkeleton();
  saved = PrototypeFactory::createSkeleton();
}

Controller::~Controller() {
  delete object;
  delete saved;
}

void Controller::loadData(std::string file_name) {
  closeObject();
  object->parse(file_name);
  if (concurrent_threads_ > 1) {
    std::thread thread_1(&Controller::processVertices, this);
    std::thread thread_2(&Controller::processFaces, this);
    thread_1.join();
    thread_2.join();
  } else {
    processVertices();
    processFaces();
  }
  *saved = *object;
  scale_ = 1.0;
}

void Controller::processVertices() {
  object->centralizeData();
  object->normalizeData();
}

void Controller::processFaces() { object->compactData(); }

void Controller::reinstateData() {
  *object = *saved;
  scale_ = 1.0;
}

void Controller::closeObject() noexcept {
  object->resetData();
  saved->resetData();
}

void Controller::rescale(double value) {
  if (concurrent_threads_ > 2)
    rescaleMT(value);
  else
    object->transformData(SCALE, ALL, value);
  scale_ *= std::fabs(value);
}
void Controller::rescaleMT(double value) {
  std::thread T1(&Controller::rescaleX, this, value);
  std::thread T2(&Controller::rescaleY, this, value);
  std::thread T3(&Controller::rescaleZ, this, value);
  T1.join();
  T2.join();
  T3.join();
}
void Controller::rescaleX(double value) {
  object->transformData(SCALE, X, value);
}
void Controller::rescaleY(double value) {
  object->transformData(SCALE, Y, value);
}
void Controller::rescaleZ(double value) {
  object->transformData(SCALE, Z, value);
}
void Controller::shiftX(double value) {
  object->transformData(SHIFT, X, value);
}
void Controller::shiftY(double value) {
  object->transformData(SHIFT, Y, value);
}
void Controller::shiftZ(double value) {
  object->transformData(SHIFT, Z, value);
}
void Controller::rotateX(double value) {
  object->transformData(ROTATE, X, value);
}
void Controller::rotateY(double value) {
  object->transformData(ROTATE, Y, value);
}
void Controller::rotateZ(double value) {
  object->transformData(ROTATE, Z, value);
}

size_t Controller::getVerticesSize() const noexcept {
  return object->getVerticesSize();
}
size_t Controller::getEdgesSize() const noexcept {
  return object->getFacesSize();
}
GVertex* Controller::getVertices() noexcept {
  return object->getVerticesData();
}
Edge* Controller::getEdges() noexcept {
  return static_cast<Edge*>(object->getFacesData());
}
size_t Controller::getCurrentLine() const noexcept {
  return object->getCurrentLine();
}
double Controller::getMaxZ() const noexcept { return object->getMaxZ(); }
double Controller::getScale() const noexcept { return scale_; }

}  // namespace s21
