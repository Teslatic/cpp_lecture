// Copyright 2018, Hendrik Vloet & Chair of AD @ University of Freiburg
// Author: Hendrik Vloet <hendrik.vloet@gmx.de>
// Using various code snippets kindly provided by
// http://ad-wiki.informatik.uni-freiburg.de/teaching

#include <gtest/gtest.h>
#include "./String.h"

// _____________________________________________________________________________

TEST(StringTest, constructor) {
  String s;
  ASSERT_EQ(0, s._length);
  // string is empty at beginning and thus should start with the null terminator
  ASSERT_EQ(0, *s._contents);
}
