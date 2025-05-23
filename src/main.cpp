// Copyright 2025 NNTU-CS
#include "train.h"

#include <chrono>
#include <iostream>
#include <random>
#include <string>
#include <vector>

using namespace std;

void runExperiment(int n, const string& mode) {
  Train train;
  random_device rd;
  mt19937 gen(rd());
  uniform_int_distribution<> dis(0, 1);

  for (int i = 0; i < n; ++i) {
    if (mode == "on") {
      train.addCar(true);
    } else if (mode == "off") {
      train.addCar(false);
    } else {  // random
      train.addCar(dis(gen));
    }
  }

  auto start = chrono::high_resolution_clock::now();
  int length = train.getLength();
  auto end = chrono::high_resolution_clock::now();

  chrono::duration<double> duration = end - start;

  cout << "Mode: " << mode << ", n = " << n
       << ", ops = " << train.getOpCount()
       << ", time = " << duration.count() << " s, length = " << length << endl;
}

int main() {
  vector<int> sizes = {2, 4, 8, 16, 32, 64, 128, 256, 512, 1000};

  for (int n : sizes) {
    runExperiment(n, "off");
    runExperiment(n, "on");
    runExperiment(n, "random");
  }

  return 0;
}
