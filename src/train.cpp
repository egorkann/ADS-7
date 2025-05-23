// Copyright 2025 NNTU-CS
#include "train.h"

Train::Train() : countOp(0), first(nullptr) {}

Train::~Train() {
  if (!first) return;
  Car* curr = first->next;
  while (curr != first) {
    Car* next = curr->next;
    delete curr;
    curr = next;
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
  Car* curr = first;
  curr->light = true;
  countOp++;

  while (true) {
    Car* runner = curr->next;
    countOp++;
    int steps = 1;

    while (!runner->light) {
      runner = runner->next;
      steps++;
      countOp++;
    }

    if (runner == curr) {
      return steps;
    }

    curr->light = false;
    curr = runner;
    countOp++;
  }
}

int Train::getOpCount() {
  return countOp;
}
