// Copyright 2018, University of Freiburg,
// Author: Hendrik Vloet <vloett@informatik.uni-freiburg.de>

#ifndef GAMEOFLIFE_H_
#define GAMEOFLIFE_H_

/*  CONSTANTS  */

// max grid size
const int MAX_GRID_SIZE = 400;
// grid starting point
const int GRID_START = 2;

// glider with relative positions of live cells, courtesy of Axel Lehmann
// <lehmann@cs.uni-freiburg.de>.
const int GLIDER[5][2] = { {1, 0}, {2, 1}, {0, 2}, {1, 2}, {2, 2} };

// glider factory with rel. pos. of live cells, courtesy of Axel Lehmann
// <lehmann@cs.uni-freiburg.de>.
const int FACTORY[36][2] = {
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
const int ACORN[7][2] = {
  {1, 0}, {3, 1}, {0, 2}, {1, 2}, {4, 2}, {5, 2}, {6, 2}
};

// __________________________________________________________________________
/*  GLOBALS  */

// step counter
extern int step;

// positions of mouse click
extern int x;
extern int y;

// come to live with probability p
extern float p;

// flow control for main function
extern int processedInput;

// pointer to current cell states
extern bool (*ptrCurrentState)[MAX_GRID_SIZE];
// pointer to next cell states
extern bool (*ptrNextState)[MAX_GRID_SIZE];

// current cell state
extern bool currentState[MAX_GRID_SIZE][MAX_GRID_SIZE];
// next cell state
extern bool nextState[MAX_GRID_SIZE][MAX_GRID_SIZE];
// __________________________________________________________________________

/*  FUNCTIONS  */

// initializes ncurses terminal
void initTerminal();

// show current state
void showState();

// update state, i.e. make one step while using 2 arrays which are copied
// around. this is not efficient and just made for understanding the
// ground problem
void updateState();

// processes keyboard and mouse input
int processUserInput();

// computes number of live neighbours around a given cell (x,y)
int aliveNeighbours(int k = 0, int j = 0);

// constructs glider at coordinates x,y
void constructGlider(int xG, int yG);

// constructs glider factory at coordinates x,y
void constructGliderFactory(int xG, int yG);

// constructs acorn at coordinates x,y
void constructAcorn(int xG, int yG);



#endif  // GAMEOFLIFE_H_
