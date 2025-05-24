// Copyright 2025 NNTU-CS
#include <gtest/gtest.h>
#include "train.h"

TEST(lab8, test1) {
  Train t;
  t.addCar(true);
  int op = t.countLightsOn();
  EXPECT_EQ(op, 1);
}

TEST(lab8, test2) {
  Train t;
  for (int i = 0; i < 8; ++i) {
    t.addCar(i % 2 == 0);
  }
  int op = t.countLightsOn();
  EXPECT_EQ(op, 4);
}

TEST(lab8, test3) {
  Train t;
  for (int i = 0; i < 1000; ++i) {
    t.addCar(i % 2 == 1);
  }
  int op = t.countLightsOn();
  EXPECT_EQ(op, 500);
}

TEST(lab8, test4) {
  Train t;
  for (int i = 0; i < 20; ++i) {
    t.addCar(true);
  }
  int op = t.countLightsOn();
  EXPECT_EQ(op, 20);
}

TEST(lab8, test5) {
  Train t;
  for (int i = 0; i < 42; ++i) {
    t.addCar(i % 3 == 0);
  }
  int op = t.countLightsOn();
  EXPECT_EQ(op, 14);
}
