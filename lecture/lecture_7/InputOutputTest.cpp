// Copyright 2018, Hendrik Vloet & Chair of AD @ University of Freiburg
// Author: Hendrik Vloet <hendrik.vloet@gmx.de>
// Using various code snippets kindly provided by
// http://ad-wiki.informatik.uni-freiburg.de/teaching

#include <gtest/gtest.h>
#include "./InputOutput.h"

// _____________________________________________________________________________

TEST(InputOutputTest, parseCommandLineArguments) {
    InputOutput io;
    int argc = 3;
    char* argv[3] = {
                     const_cast<char*>("./InputOutputMain"),
                     const_cast<char*>("--head=10"),
                     const_cast<char*>("-n")
    };
    ::testing::FLAGS_gtest_death_test_style = "threadsafe";
    ASSERT_DEATH(io.parseCommandLineArguments(argc, argv), "Usage: .*");
}

