// Copyright 2018, Hendrik Vloet & Chair of AD @ University of Freiburg
// Author: Hendrik Vloet <hendrik.vloet@gmx.de>
// Using various code snippets kindly provided by
// http://ad-wiki.informatik.uni-freiburg.de/teaching

#ifndef GAMEOFLIFE_H_
#define GAMEOFLIFE_H_

#include <gtest/gtest.h>
const int GRID = 300;

class GameOfLife  {
 private:
  // current state array
  bool _currentState[GRID][GRID];
  // next state array
  bool _nextState[GRID][GRID];
  // pointer to the current state 
  bool (*_ptrCurrentState)[GRID];
  // pointer to the next state
  bool (*_ptrNextState)[GRID];

  // number of total alive cells
  int _aliveCells;
  // generation counter
  int _generation;
  // x coordinate of last mouse click
  int _x;
  // y coordinate of last mouse click
  int _y;

  int _rx;
  int _ry;

  // glider with relative positions of live cells, courtesy of Axel Lehmann
  // <lehmann@cs.uni-freiburg.de>.
  int _GLIDER[5][2] = { {1, 0}, {2, 1}, {0, 2}, {1, 2}, {2, 2} };

  // glider factory with rel. pos. of live cells, courtesy of Axel Lehmann
  // <lehmann@cs.uni-freiburg.de>.
  int _FACTORY[36][2] = {
                              {24, 0},
                              {22, 1}, {24, 1},
                              {12, 2}, {13, 2}, {20, 2}, {21, 2}, {34, 2}, {35, 2},
                              {11, 3}, {15, 3}, {20, 3}, {21, 3}, {34, 3}, {35, 3},
                              {0, 4}, {1, 4}, {10, 4}, {16, 4}, {20, 4}, {21, 4},
                              {0, 5}, {1, 5}, {10, 5}, {14, 5}, {16, 5}, {17, 5}, {22, 5}, {24, 5},
                              {10, 6}, {16, 6}, {24, 6},
                              {11, 7}, {15, 7},
                              {12, 8}, {13, 8}
  };

  // acorn with relative positions of live cells
  int _ACORN[7][2] = {
                           {1, 0}, {3, 1}, {0, 2}, {1, 2}, {4, 2}, {5, 2}, {6, 2}
  };

  int _GALAXY[28][2] = {{2, 0}, {5, 0}, {7, 0},
                        {0, 1}, {1, 1}, {3, 1}, {5, 1}, {6, 1}, {7, 1},
                        {1, 2}, {8, 2},
                        {0, 3}, {1, 3}, {7, 3},
                        {1, 5}, {7, 5}, {8, 5},
                        {0, 6}, {7, 6},
                        {1, 7}, {2, 7}, {3, 7}, {5, 7}, {7, 7}, {8, 7},
                        {1, 8}, {3, 8}, {6, 8}};

  // counts alive neighbours around one cell
  int aliveNeighbours(int x, int y);
  // initalizes terminal, state arrays and pointer
  void initialize();
  // displays current state in the terminal
  void showState();
  // draw a cell
  void drawCell(int x, int y);
  // erase a cell
  void eraseCell(int x, int y);
  // calculates the result state
  void updateState();
  FRIEND_TEST(GameOfLifeTest, updateState);
  // processes keystrokes on the keyboard by the user
  int processUserInput();
  // constructs a glider at position x,y
  void constructGlider(int x, int y);
  // constructs a gliderfactory at position x,y
  void constructGliderFactory(int x, int y);
  // constructs an acorn at position x,y
  void constructAcorn(int x, int y);
  // construcs Kok's Galaxy
  void constructKokGalaxy(int x, int y);
 public:
  GameOfLife();  // Constructor
  ~GameOfLife(); // Destructor
  // controls the playflow, called in main
  void play();
};




#endif  // GAMEOFLIFE_H_
