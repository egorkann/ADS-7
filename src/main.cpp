// Copyright 2025 NNTU-CS
#include "train.h"

#include <iostream>
#include <string>

int main() {
  Train train;
  train.addCar(true);
  train.addCar(false);
  train.addCar(true);

  std::cout << "Train length: " << train.getLength() << std::endl;
  std::cout << "Lights on: " << train.countLightsOn() << std::endl;
  std::cout << "Operations: " << train.getOpCount() << std::endl;

  return 0;
}
