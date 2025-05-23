// Copyright 2025 NNTU-CS
#include "../include/train.h"

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

void Train::addCar(bool light) {
  Car* newCar = new Car(light);
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
  if (!first) return 0;
  int length = 0;
  Car* curr = first;
  do {
    ++length;
    ++countOp;
    curr = curr->next;
  } while (curr != first);
  return length;
}

int Train::getOpCount() {
  return countOp;
}
