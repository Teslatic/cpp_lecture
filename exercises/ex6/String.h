// Copyright 2018, Hendrik Vloet & Chair of AD @ University of Freiburg
// Author: Hendrik Vloet <hendrik.vloet@gmx.de>
// Using various code snippets kindly provided by
// http://ad-wiki.informatik.uni-freiburg.de/teaching

// _____________________________________________________________________________

#ifndef STRING_H_
#define STRING_H_

#include <gtest/gtest.h>

class String {
 public:
  String();
  String(const String& s);
  ~String();

 private:
  //  Null terminated C-style string to make it usable by C func., eg. printf
  FRIEND_TEST(StringTest, constructor);
  FRIEND_TEST(StringTest, copyConstructor);
  FRIEND_TEST(StringTest, set);
  FRIEND_TEST(StringTest, count);
  FRIEND_TEST(StringTest, toFloat);
  FRIEND_TEST(StringTest, split);
  FRIEND_TEST(StringTest, splitTooManyDelimiters);
  FRIEND_TEST(StringTest, splitTooFewDelimiters);
  FRIEND_TEST(StringTest, splitNoDelimiter);
  char* _contents;
  //  the length of the string, we keep track of this explicitly so that we can
  //  answer length queries in constant line.
  int _length;

  //  keep track of the number of objects
  static int _numObjects;

  // set to given C-style string
  void set(const char* s);
  // counts occurence of character in given object string
  int count(const char& s);

  // converts given argument characters to float
  float toFloat();

  // splits given string into its character pieces
  void split(const char& delimiter, const int numPieces, String parts[]);
};

#endif  //  STRING_H_
// _____________________________________________________________________________
