// Copyright 2025 NNTU-CS
#include <iostream>
#include "train.h"

int main() {
  Train train;
  train.addCar(true);
  train.addCar(false);

  std::cout << "Length: " << train.getLength() << '\n';
  std::cout << "Lights on: " << train.countLightsOn() << '\n';
  std::cout << "Operations: " << train.getOpCount() << '\n';

  return 0;
}
