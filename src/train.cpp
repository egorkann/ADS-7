// Copyright 2025 NNTU-CS
#include "../include/train.h"

Train::Train() : head_(nullptr), tail_(nullptr), length_(0) {}

Train::~Train() {
  Car* curr = head_;
  while (curr) {
    Car* next = curr->next;
    delete curr;
    curr = next;
  }
}

void Train::addCar(bool light) {
  Car* newCar = new Car(light);
  if (!head_) {
    head_ = tail_ = newCar;
  } else {
    tail_->next = newCar;
    newCar->prev = tail_;
    tail_ = newCar;
  }
  ++length_;
}

int Train::getLength() const {
  return length_;
}

int Train::countLightsOn() const {
  int count = 0;
  Car* curr = head_;
  while (curr) {
    if (curr->light) ++count;
    curr = curr->next;
  }
  return count;
}
