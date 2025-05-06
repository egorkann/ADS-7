// Copyright 2025 NNTU-CS
#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <fstream>
#include <string>

#include "train.h"

void runExperiment(int maxN, const std::string& mode,
                   std::ofstream& opsOut, std::ofstream& timeOut) {
  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_int_distribution<> dis(0, 1);

  for (int n = 2; n <= maxN; ++n) {
    Train train;

    for (int i = 0; i < n; ++i) {
      if (mode == "all_off") {
        train.addCar(false);
      } else if (mode == "all_on") {
        train.addCar(true);
      } else {
        train.addCar(dis(gen));
      }
    }

    auto start = std::chrono::high_resolution_clock::now();
    train.getLength();  
    auto end = std::chrono::high_resolution_clock::now();

    std::chrono::duration<double> elapsed = end - start;

    opsOut << n << "," << train.getOpCount() << "\n";
    timeOut << n << "," << elapsed.count() << "\n";
  }
}

int main() {
  std::ofstream ops1("result/ops_all_off.csv");
  std::ofstream time1("result/time_all_off.csv");
  runExperiment(200, "all_off", ops1, time1);

  std::ofstream ops2("result/ops_all_on.csv");
  std::ofstream time2("result/time_all_on.csv");
  runExperiment(200, "all_on", ops2, time2);

  std::ofstream ops3("result/ops_random.csv");
  std::ofstream time3("result/time_random.csv");
  runExperiment(200, "random", ops3, time3);

  std::cout << "Эксперименты завершены. Результаты записаны.\n";
  return 0;
}
