// Copyright 2018, Hendrik Vloet & Chair of AD @ University of Freiburg
// Author: Hendrik Vloet <hendrik.vloet@gmx.de>
// Using various code snippets kindly provided by
// http://ad-wiki.informatik.uni-freiburg.de/teaching

#ifndef INPUTOUTPUT_H_
#define INPUTOUTPUT_H_

// class for demonstration of input output code

class InputOutput {
 public:
  // process given input file
  void process();
  // parse the command line input
  void parseCommandLineArguments(int argc, char** argv);

 private:
  // name of the input file
  const char* _filename;

  // show only this many lines
  int _headCount = 10;

  // show line numbers or not
  bool _showLineNumbers = false;
};

#endif  // INPUTOUTPUT_H_
