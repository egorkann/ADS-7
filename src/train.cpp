// Copyright 2025 NNTU-CS
#include "train.h"

Train::Train() : op_count_(0) {}

void Train::addCar(bool hasLight) {
  ++op_count_;
  cars_.push_back(hasLight);
}

int Train::countLightsOn() const {
  ++op_count_;
  int count = 0;
  for (bool light : cars_) {
    ++op_count_;
    if (light) {
      ++count;
    }
  }
  return count;
}

int Train::getLength() const {
  ++op_count_;
  return static_cast<int>(cars_.size());
}

int Train::getOpCount() const {
  return op_count_;
}
