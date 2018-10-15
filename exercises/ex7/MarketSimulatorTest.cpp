// Copyright 2018, University of Freiburg,
// Chair of Algorithms and Data Structures.
// Author: Axel Lehmann <lehmann@cs.uni-freiburg.de>.

// #include <gtest/gtest.h>
// #include "./MarketSimulator.h"

// // _____________________________________________________________________________
// test(marketsimulatortest, constructor) {
//   marketsimulator market;
//   assert_streq("", market._inputfilename);
//   assert_eq(0, market._seedmoney);
//   assert_false(market._verbose);
// }

// // _____________________________________________________________________________
// test(marketsimulatortest, parsecommandlineargumentsnoarguments) {
//   marketsimulator market;
//   int argc = 1;
//   char* argv[1] = {
//     const_cast<char*>("")
//   };
//   ::testing::flags_gtest_death_test_style = "threadsafe";
//   assert_death(market.parsecommandlinearguments(argc, argv), "usage: .*");
// }

// // _____________________________________________________________________________
// test(marketsimulatortest, parsecommandlinearguments) {
//   marketsimulator market;
//   int argc = 2;
//   char* argv[2] = {
//     const_cast<char*>(""),
//     const_cast<char*>("myinputfile")
//   };
//   market.parsecommandlinearguments(argc, argv);
//   assert_streq("myinputfile", market._inputfilename);
//   assert_float_eq(1000, market._seedmoney);
// }

// // _____________________________________________________________________________
// test(marketsimulatortest, parsecommandlineargumentssetfunds) {
//   marketsimulator market;
//   int argc = 4;
//   char* argv[4] = {
//     const_cast<char*>(""),
//     const_cast<char*>("--seed-money"),
//     const_cast<char*>("1337"),
//     const_cast<char*>("myinputfile")
//   };
//   market.parsecommandlinearguments(argc, argv);
//   assert_streq("myinputfile", market._inputfilename);
//   assert_float_eq(1337, market._seedmoney);
// }

// // _____________________________________________________________________________
// test(marketsimulatortest, printusageandexit) {
//   marketsimulator market;
//   ::testing::flags_gtest_death_test_style = "threadsafe";
//   assert_death(market.printusageandexit(), "usage: .*");
// }

// // _____________________________________________________________________________
// test(marketsimulatortest, simulatecantopeninputfile) {
//   marketsimulator market;
//   trader trader;
//   market._inputfilename = "doesnotexist";
//   ::testing::flags_gtest_death_test_style = "threadsafe";
//   assert_death(market.simulate(&trader), "error: could not open input .*");
// }

// // _____________________________________________________________________________
// test(marketsimulatortest, simulatesimpletraderinteraction) {
//   marketsimulator market;
//   trader trader;
//   market._inputfilename = "inputtest.csv";
//   market._verbose = false;
//   market._seedmoney = 10;

//   file* inputfile = fopen(market._inputfilename, "w");
//   fprintf(inputfile, "lorem,0.5\nipsum,0.6,dolor\nsit,1.0\namet,2.0\n");
//   fclose(inputfile);

//   market.simulate(&trader);
//   assert_eq(2, trader._assets);
//   assert_float_eq(7, trader._money);

//   unlink(market._inputfilename);
// }
