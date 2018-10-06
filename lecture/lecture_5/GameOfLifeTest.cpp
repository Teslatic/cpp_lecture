// Copyright 2018, Hendrik Vloet & Chair of AD @ University of Freiburg
// Author: Hendrik Vloet <hendrik.vloet@gmx.de>
// Using various code snippets kindly provided by
// http://ad-wiki.informatik.uni-freiburg.de/teaching

#include <gtest/gtest.h>
#include "./GameOfLife.h"

// _____________________________________________________________________________
TEST(GameOfLifeTest, updateState) {
  GameOfLife game;

  // printf("%p\n", static_cast<void*>(&game));
  game._state[0][0] =  0;
  game._state[0][1] =  0;
  game._state[0][2] =  0;
  game._state[1][0] =  0;
  game._state[1][1] =  1;
  game._state[1][2] =  0;
  game._state[2][0] =  0;
  game._state[2][1] =  0;
  game._state[2][2] =  0;

  ASSERT_EQ(1, game._state[1][1]);
  game.updateState();
  ASSERT_EQ(0, game._state[1][1]);
}

int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
