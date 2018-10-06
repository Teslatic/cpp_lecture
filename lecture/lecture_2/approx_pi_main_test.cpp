// Copyright 2018, Hendrik Vloet <hendrik.vloet@gmx.de>
// Using various code snippets kindly provided by
// http://ad-wiki.informatik.uni-freiburg.de/teaching


#include <gtest/gtest.h>
#include  "./approx_pi.h"

TEST(approx_pi, approxPiCircleMethod) {
  ASSERT_EQ(5, approxPiCircleMethod(1));
  ASSERT_EQ(13, approxPiCircleMethod(2));
  ASSERT_EQ(29, approxPiCircleMethod(3));
}

int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
