// Copyright 2018, Hendrik Vloet & Chair of AD @ University of Freiburg
// Author: Hendrik Vloet <hendrik.vloet@gmx.de>
// Using various code snippets kindly provided by
// http://ad-wiki.informatik.uni-freiburg.de/teaching

// _____________________________________________________________________________

#ifndef STRING_H_
#define STRING_H_

class String {
 public:
  String();
  ~String();
  //  Null terminated C-style string to make it usable by C func., eg. printf
  char* _contents;
  //  the length of the string, we keep track of this explicitly so that we can
  //  answer length queries in constant line.
  int _length;
};

#endif  //  STRING_H_
// _____________________________________________________________________________
