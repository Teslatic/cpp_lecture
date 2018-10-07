// Copyright 2018, Hendrik Vloet & Chair of AD @ University of Freiburg
// Author: Hendrik Vloet <hendrik.vloet@gmx.de>
// Using various code snippets kindly provided by
// http://ad-wiki.informatik.uni-freiburg.de/teaching

#include <stdio.h>
#include "./String.h"
// _____________________________________________________________________________
String::String() {
  _length = 0;
  _contents = new char[1];
  *_contents = 0;
}

// _____________________________________________________________________________
String::~String()  {
  delete[] _contents;
}
