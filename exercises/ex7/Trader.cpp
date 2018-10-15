// Copyright 2018, Hendrik Vloet & Chair of AD @ University of Freiburg
// Author: Hendrik Vloet <hendrik.vloet@gmx.de>
// Using various code snippets kindly provided by
// http://ad-wiki.informatik.uni-freiburg.de/teaching

#include <stdio.h>
#include "./Trader.h"



// _____________________________________________________________________________

Trader::Trader() {
  _verbose = false;
  _money = 0;
  _seedMoney = 0;
  _assets = 0;
  _lastPrices = new int[3];
  for (int i = 0; i < 2; i++) {_lastPrices[i] = 0 ; }
}


// _____________________________________________________________________________
Trader::~Trader() {
  delete[] _lastPrices;
}
