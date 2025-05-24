// Copyright 2025 NNTU-CS
#ifndef TRAIN_H_
#define TRAIN_H_

#include <vector>

class Train {
 public:
  Train();

  void addCar(bool hasLight);
  int countLightsOn() const;
  int getLength() const;
  int getOpCount() const;

 private:
  std::vector<bool> cars_;
  mutable int op_count_;
};

#endif  // TRAIN_H_
