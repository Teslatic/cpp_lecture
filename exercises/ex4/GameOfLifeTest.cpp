// Copyright 2018, University of Freiburg,
// Author: Hendrik Vloet <vloett@informatik.uni-freiburg.de>

#include <gtest/gtest.h>
#include "./GameOfLife.h"

TEST(GameOfLife, aliveNeighbours) {
  ASSERT_EQ(7, aliveNeighbours(5, 5));
}
