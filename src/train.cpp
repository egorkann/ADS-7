// Copyright 2025 NNTU-CS
#include "train.h"

Train::Train() : head_(nullptr), tail_(nullptr), length_(0), opCount_(0) {}

Train::~Train() {
  while (head_ != nullptr) {
    Car* tmp = head_;
    head_ = head_->next;
    delete tmp;
  }
}

void Train::addCar(bool light) {
  Car* newCar = new Car(light);
  if (tail_) {
    tail_->next = newCar;
  } else {
    head_ = newCar;
  }
  tail_ = newCar;
  ++length_;
  ++opCount_;
}

int Train::countLightsOn() const {
  int count = 0;
  Car* current = head_;
  while (current != nullptr) {
    if (current->lightOn) {
      ++count;
    }
    current = current->next;
    ++opCount_;
  }
  return count;
}

int Train::getLength() const {
  ++opCount_;
  return length_;
}

int Train::getOpCount() const {
  return opCount_;
}
