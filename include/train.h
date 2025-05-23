// Copyright 2025 NNTU-CS
#ifndef INCLUDE_TRAIN_H_
#define INCLUDE_TRAIN_H_

class Train {
 public:
  Train();
  ~Train();
  void addCar(bool light);
  int countLightsOn() const;
  int getLength() const;
  int getOpCount() const;

 private:
  struct Car {
    bool lightOn;
    Car* next;
    Car(bool light) : lightOn(light), next(nullptr) {}
  };

  Car* head_;
  Car* tail_;
  int length_;
  mutable int opCount_;
};

#endif  // INCLUDE_TRAIN_H_
