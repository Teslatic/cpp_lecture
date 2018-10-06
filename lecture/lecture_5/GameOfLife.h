// Copyright 2018, Hendrik Vloet & Chair of AD @ University of Freiburg
// Author: Hendrik Vloet <hendrik.vloet@gmx.de>
// Using various code snippets kindly provided by
// http://ad-wiki.informatik.uni-freiburg.de/teaching


#ifndef GAMEOFLIFE_H_
#define GAMEOFLIFE_H_
#include <gtest/gtest.h>

class GameOfLife  {
 private:
  bool _state[3][3];  //  current state, underscore as member convention
  static int _numObjects;
 public:
  // constructors
  GameOfLife();
  explicit GameOfLife(int x);

  // destructor
  ~GameOfLife();

  void updateState();
  FRIEND_TEST(GameOfLifeTest, updateState);
};

#endif  // GAMEOFLIFE_H_
