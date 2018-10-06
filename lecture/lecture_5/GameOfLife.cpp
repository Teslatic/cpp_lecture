// Copyright 2018, Hendrik Vloet & Chair of AD @ University of Freiburg
// Author: Hendrik Vloet <hendrik.vloet@gmx.de>
// Using various code snippets kindly provided by
// http://ad-wiki.informatik.uni-freiburg.de/teaching

#include <stdio.h>
#include "./GameOfLife.h"

int GameOfLife::_numObjects = 0;
int x = 0;
// _____________________________________________________________________________

GameOfLife::GameOfLife() {
  _numObjects++;
  printf("Hello, I am the constructor #%d! \n", _numObjects);
}

// _____________________________________________________________________________

GameOfLife::GameOfLife(int x) {
  printf("Hello, I was called with argument %d\n", x);
}

// _____________________________________________________________________________
GameOfLife::~GameOfLife() {
  printf("So long!\n");
}
// _____________________________________________________________________________

void GameOfLife::updateState()  {
  bool state = _state[1][1];
  int numAlive = -state;
  for (int x = 0; x < 3; x++) {
    for (int y = 0; y < 3; y++) {
      numAlive += _state[x][y];
    }
  }
  if (state == 1 && (numAlive < 2 || numAlive > 3)) {
    state = 0;
  }
  if (state == 0 && numAlive == 3) {
    state = 1;
  }
  _state[1][1] = state;
  // printf("%p\n", static_cast<void*>(this));
}
