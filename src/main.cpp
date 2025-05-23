// Copyright 2025 NNTU-CS
#include "train.h"

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdlib>

int main() {
  Train train;
  train.addCar(true);
  train.addCar(false);
  train.addCar(true);

  std::cout << "Length: " << train.getLength() << std::endl;
  std::cout << "Lights On: " << train.countLightsOn() << std::endl;

  return 0;
}
