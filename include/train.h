// Copyright 2025 NNTU-CS
#ifndef INCLUDE_TRAIN_H_
#define INCLUDE_TRAIN_H_

class Train {
 private:
  struct Car {
    bool light;
    Car* next;
    Car* prev;
  };

  Car* first;
  int countOp;

 public:
  Train();
  ~Train();

  void addCar(bool light);
  int getLength();
  int getOpCount();

 private:
  Car* createCar(bool light);
};

#endif  // INCLUDE_TRAIN_H_
