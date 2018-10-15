// Copyright 2018, Hendrik Vloet & Chair of AD @ University of Freiburg
// Author: Hendrik Vloet <hendrik.vloet@gmx.de>
// Using various code snippets kindly provided by
// http://ad-wiki.informatik.uni-freiburg.de/teaching

#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>
#include "./InputOutput.h"

// _____________________________________________________________________________
void InputOutput::parseCommandLineArguments(int argc, char** argv) {
  struct option options[] = {
    {"head", 1, NULL, 'h' },
    {"numbers", 0, NULL, 'n'},
    {NULL, 0, NULL, 0}
  };
  optind = 1;
  while (true) {
    char c = getopt_long(argc, argv, "h:n", options, NULL);
    if (c == -1) { break; }
    switch (c) {
      case 'h': _headCount = atoi(optarg);
        printf("headcount: %d\n", _headCount);
        break;
      case 'n': _showLineNumbers = true;
        break;
    }
  }
  if (optind + 1 != argc) {
    fprintf(stderr,
            "Usage: ./InputOutputMain [options] <filename>\n"
           "-h, --head=N  : show only first N lines\n"
           "-n, --numbers : prefix each line with its line number\n");
    exit(1);
  }
  _filename = argv[optind];
}



// _____________________________________________________________________________
void InputOutput::process() {
  // _filename = "example.csv";
  FILE* file = fopen(_filename, "r");
  if (file == NULL) {
    perror(_filename);
    exit(1);
  }
  int lineCount = 0;
  while (true) {
    const int kMaxLineLength = 1000;
    char line[kMaxLineLength + 1];
    fgets(line, kMaxLineLength, file);
    lineCount++;
    if (feof(file) || lineCount > _headCount) {break; }
    if (_showLineNumbers) { printf("%04d. ", lineCount); }
    printf("%s", line);
  }
  fclose(file);
}

