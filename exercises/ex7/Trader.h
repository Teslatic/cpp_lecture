// Copyright 2018, Hendrik Vloet & Chair of AD @ University of Freiburg
// Author: Hendrik Vloet <hendrik.vloet@gmx.de>
// Using various code snippets kindly provided by
// http://ad-wiki.informatik.uni-freiburg.de/teaching


#ifndef TRADER_H_
#define TRADER_H_

#include <gtest/gtest.h>

class Trader {
 private:
  FRIEND_TEST(TraderTest, constructor);
  Trader();
  ~Trader();
  bool _verbose;
  int _money;
  int _seedMoney;
  int _assets;
  int* _lastPrices;
};

#endif  //  TRADER_H_
