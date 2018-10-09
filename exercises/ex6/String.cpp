// Copyright 2018, Hendrik Vloet & Chair of AD @ University of Freiburg
// Author: Hendrik Vloet <hendrik.vloet@gmx.de>
// Using various code snippets kindly provided by
// http://ad-wiki.informatik.uni-freiburg.de/teaching

#include <stdio.h>
#include <string.h>
#include "./String.h"
// _____________________________________________________________________________
String::String() {
  _length = 0;
  _contents = new char[1];
  *_contents = 0;
}
// _____________________________________________________________________________
String::String(const String& s) {
  _contents = 0;
  set(s._contents);
}
// _____________________________________________________________________________
String::~String()  {
  delete[] _contents;
}
// _____________________________________________________________________________

void String::set(const char* s) {
  _length = strlen(s);
  delete[] _contents;
  _contents = new char[_length + 1];  //  +1 to debounce strlen returns 0
  for (int i = 0; i < _length + 1; i++) { _contents[i] = s[i]; }
}
// _____________________________________________________________________________

int String::count(const char& s) {
  int numCharacter = 0;
  for (int i = 0; i < _length; i++) {
    if (_contents[i] == s) {
      numCharacter++;
    }
  }
  return numCharacter;
}
// _____________________________________________________________________________

float String::toFloat() {
  float convResult = atof(_contents);
  return convResult;
}
// _____________________________________________________________________________

void String::split(const char& delimiter, const int numPieces, String parts[]) {
  int cnt = 0;
  int matches = 0;
  char* buffer = new char[_length + 1];
  for (int i = 0; i <= _length; i++) { buffer[i] = 0; }

  for (int i = 0; i < _length; i++) {
    if (_contents[i] == delimiter && matches < numPieces - 1) {
      parts[matches++].set(buffer);
      cnt = 0;
      for (int j = 0; j <= _length; j++) { buffer[j] = 0; }
      continue;
    }
    buffer[cnt++] = _contents[i];
  }
  parts[matches].set(buffer);
  delete[] buffer;
}

// _____________________________________________________________________________
