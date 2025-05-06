// Copyright 2025 NNTU-CS
#include "train.h"

Train::Train() : first(nullptr), countOp(0) {}

Train::~Train() {
  if (!first) return;
  Car* curr = first->next;
  while (curr != first) {
    Car* temp = curr;
    curr = curr->next;
    delete temp;
  }
  delete first;
}

Train::Car* Train::createCar(bool light) {
  Car* car = new Car{light, nullptr, nullptr};
  return car;
}

void Train::addCar(bool light) {
  Car* newCar = createCar(light);
  if (!first) {
    first = newCar;
    first->next = first;
    first->prev = first;
  } else {
    Car* last = first->prev;
    last->next = newCar;
    newCar->prev = last;
    newCar->next = first;
    first->prev = newCar;
  }
}

int Train::getLength() {
  Car* curr = first;
  curr->light = true;
  countOp = 0;

  while (true) {
    countOp++;
    curr = curr->next;

    if (!curr->light) {
      curr->light = true;

      const Car* back = curr;
      int len = 1;
      while (true) {
        countOp++;
        back = back->next;
        len++;
        if (back->light) break;
      }
      return len;
    }
  }
}

int Train::getOpCount() {
  return countOp;
}
