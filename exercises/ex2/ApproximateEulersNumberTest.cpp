// Copyright 2018, University of Freiburg,
// Author: Hendrik Vloet <vloett@informatik.uni-freiburg.de>

#include <gtest/gtest.h>
#include <math.h>
#include "./ApproximateEulersNumber.h"

TEST(ApproximateEulersNumber, ApproximateEulersNumber) {
  ASSERT_FLOAT_EQ(M_E, ApproximateEulersNumber(15));
}

TEST(ApproximateEulersNumber, ApproximateEulersNumberIntegralMethod) {
  ASSERT_FLOAT_EQ(M_E, ApproximateEulersNumberIntegralMethod(15));
}



int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
