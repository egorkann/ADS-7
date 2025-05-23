// Copyright 2025 NNTU-CS
#include "../include/train.h"
#include <iostream>
#include <random>
#include <chrono>
#include <vector>

void runExperiment(int n, const std::string& caseType) {
    Train train;
    std::random_device rd;
    std::mt19937 gen(rd());
    std::bernoulli_distribution dist(0.5);

    for (int i = 0; i < n; ++i) {
        if (caseType == "on") {
            train.addCar(true);
        } else if (caseType == "off") {
            train.addCar(false);
        } else {
            train.addCar(dist(gen));
        }
    }

    auto start = std::chrono::high_resolution_clock::now();
    int len = train.getLength();
    auto end = std::chrono::high_resolution_clock::now();

    std::chrono::duration<double> duration = end - start;

    std::cout << "Type: " << caseType
              << ", Length: " << len
              << ", Steps: " << train.getOpCount()
              << ", Time: " << duration.count() << "s\n";
}

int main() {
    std::vector<int> sizes = {10, 100, 500, 1000};

    for (int n : sizes) {
        runExperiment(n, "off");
        runExperiment(n, "on");
        runExperiment(n, "rand");
    }

    return 0;
}
