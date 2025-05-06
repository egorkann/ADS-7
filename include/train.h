// Copyright 2025 NNTU-CS
#ifndef TRAIN_H
#define TRAIN_H

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

#endif
