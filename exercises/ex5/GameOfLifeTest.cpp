// Copyright 2018, Hendrik Vloet & Chair of AD @ University of Freiburg
// Author: Hendrik Vloet <hendrik.vloet@gmx.de>
// Using various code snippets kindly provided by
// http://ad-wiki.informatik.uni-freiburg.de/teaching

#include <ncurses.h>
#include "./GameOfLife.h"
#include <gtest/gtest.h>

TEST(GameOfLifeTest, updateState) {
  // printf("%p\n", static_cast<void*>(&game));
   
  GameOfLife game1;
 
  game1._currentState[4][0] =  0;
  game1._currentState[4][1] =  0;
  game1._currentState[4][2] =  0;
  game1._currentState[5][4] =  1;
  game1._currentState[5][5] =  0;
  game1._currentState[5][6] =  1;
  game1._currentState[6][0] =  0;
  game1._currentState[6][1] =  0;
  game1._currentState[6][2] =  0;

  ASSERT_EQ(0, game1._currentState[5][5]);
  game1.updateState();
  ASSERT_EQ(0, game1._currentState[5][5]);

  GameOfLife game2;
  game2._currentState[4][0] =  0;
  game2._currentState[4][1] =  0;
  game2._currentState[4][2] =  0;
  game2._currentState[5][4] =  1;
  game2._currentState[5][5] =  1;
  game2._currentState[5][6] =  1;
  game2._currentState[6][0] =  0;
  game2._currentState[6][1] =  0;
  game2._currentState[6][2] =  0;

  ASSERT_EQ(1, game2._currentState[5][5]);
  game2.updateState();
  ASSERT_EQ(1, game2._currentState[5][5]);
}

int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}

