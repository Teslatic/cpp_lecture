// Copyright 2018, Hendrik Vloet & Chair of AD @ University of Freiburg
// Author: Hendrik Vloet <hendrik.vloet@gmx.de>
// Using various code snippets kindly provided by
// http://ad-wiki.informatik.uni-freiburg.de/teaching

#include <stdio.h>
#include <unistd.h>
#include "./GameOfLife.h"
#include <ncurses.h>

GameOfLife::GameOfLife()  {
  printf("Welcome to the Game of Life!\n");
}

// _____________________________________________________________________________

GameOfLife::~GameOfLife()  {
  endwin();
}

// _____________________________________________________________________________

void GameOfLife::initialize()  {
  initscr();
  cbreak();
  noecho();
  curs_set(false);
  nodelay(stdscr, true);
  keypad(stdscr, true);
  mousemask(ALL_MOUSE_EVENTS, NULL);
  _generation = 1;
  for (int i = 0; i < GRID; i++) {
    for (int j = 0; j < GRID; j++) {
      _currentState[j][i] =  0;
      _nextState[j][i] = 0 ;
    }
  }
  _ptrCurrentState = _currentState;
  _ptrNextState = _nextState;
}

// _____________________________________________________________________________

void GameOfLife::showState()  {
  int population = 0;
  for (int j = 0; j < GRID; j++) {
    for (int k = 0; k < GRID; k++) {
      if (_ptrCurrentState[k][j] == 1)  {
        population++;
        attron(A_REVERSE);
        mvprintw(j, k, " ");
        attroff(A_REVERSE);
      } else  {
        mvprintw(j, k, " ");
      }
    }
  }
  mvprintw(0, 0, "Generation: %d", _generation);
  mvprintw(1, 0, "Population: %d", population);
  // mvprintw(2, 0, "probability: %1.1f", p);
  refresh();
}

// _____________________________________________________________________________

int GameOfLife::aliveNeighbours(int l, int k) {
  int healthyNeighbours = 0;
  int lowBoundX = 1;
  int highBoundX = 1;
  int lowBoundY = 1;
  int highBoundY = 1;

  switch (l)  {
    case 0:
    lowBoundX = 0;
    highBoundX = 1;
    break;
    case GRID - 1:
      lowBoundX = 1;
      highBoundX = 0;
      break;
    default:
      lowBoundX = 1;
      highBoundX = 1;
      break;
  }
  switch (k)  {
    case 0:
    lowBoundY = 0;
    highBoundY = 1;
    break;
    case GRID - 1:
      lowBoundY = 1;
      highBoundY = 0;
      break;
    default:
      lowBoundY = 1;
      highBoundY = 1;
      break;
  }
  // loop over neightbours and count live neighbours
  for (int m = k - lowBoundY; m <= k + highBoundY; m++)  {
    for (int n = l - lowBoundX; n <= l + highBoundX ; n++)  {
      if (_ptrCurrentState[n][m] == 1) {
        healthyNeighbours++;
      }
    }
  }
  // alive center cell should not count as neighbour
  if (_ptrCurrentState[l][k] == 1) {
    healthyNeighbours--;
  }
  return healthyNeighbours;
}

// _____________________________________________________________________________

void GameOfLife::updateState()  {
  int livingNeighbours = 0;
  // loop over whole grid
  for (int k = 0; k < GRID; k++) {
    for (int l = 0; l < GRID; l++) {
      livingNeighbours = aliveNeighbours(l, k);
      // dead cell rules
      if (_ptrCurrentState[l][k] == 0)  {
        // cell comes to live
        if (livingNeighbours == 3)  {
          _ptrNextState[l][k] = 1;
        } else  {
          _ptrNextState[l][k] = 0;
        }
      } else  {
        if (livingNeighbours == 3 || livingNeighbours == 2)  {
          // cell survives
          _ptrNextState[l][k] = 1;
        } else  {
          _ptrNextState[l][k] = 0;
        }
      }
    }
  }
   _ptrNextState = (_generation % 2 == 0) ? _currentState : _nextState;
   _ptrCurrentState = (_generation % 2 == 0) ?  _nextState : _currentState;
  _generation++;
}

// _____________________________________________________________________________

int GameOfLife::processUserInput() {
  int key = getch();
  switch (key)  {
  case KEY_MOUSE:
    MEVENT event;           // MEVENT is a struct
    if (getmouse(&event) == OK && event.bstate & BUTTON1_CLICKED) {
     _x = event.x;
     _y = event.y;
      _ptrCurrentState[_x][_y] = !_ptrCurrentState[_x][_y];
      return 0;
    }
  case 's':   // make one _generation while in pause mode
    return 1;
  case ' ':   // pause/continue
    return 2;
  case 103:   // place glider at x,y
    return 3;
  case 'G':   // place glider facility at x,y
    return 4;
  case 'a':   // place acorn
    return 5;
  case 'r':
    return 6;
  case 27:    // ESC-KEY
    return -1;
  default:
    return 0;
  }
}

// _____________________________________________________________________________

void GameOfLife::play() {
  initialize();
  while (true) {
    int userInput = processUserInput();
    updateState();
    showState();
    if (userInput == 2) {
      userInput = processUserInput();
      while (userInput != 2) {
        userInput = processUserInput();
        showState();
        if (userInput == 1) {
          updateState();
        }
        if (userInput == 3) {
          constructGlider(_x, _y);
        }
        if (userInput == 4) {
          constructGliderFactory(_x, _y);
        }
        if (userInput == 5) {
          constructAcorn(_x, _y);
        }
        if (userInput == -1) {
          break;
        }
      }
    }
    if (userInput == -1) {
      break;
    }
    usleep(10 * 1000);
  }
}



// _____________________________________________________________________________

void GameOfLife::constructGlider(int xG, int yG)  {
  int const (*ptrGlider)[2] = _GLIDER;
  int markerX = 0;
  int markerY = 0;
  for (int i=0; i < 5; i++) {
    markerX = ptrGlider[i][0];
    markerY = ptrGlider[i][1];
    _ptrCurrentState[xG + markerX][yG + markerY] = 1;
  }
  _ptrCurrentState[xG][yG] = 0;
}

// _____________________________________________________________________________

void GameOfLife::constructGliderFactory(int xG, int yG)  {
  int const (*ptrGliderFactory)[2] = _FACTORY;
  int markerX = 0;
  int markerY = 0;
  for (int i=0; i < 36; i++) {
    markerX = ptrGliderFactory[i][0];
    markerY = ptrGliderFactory[i][1];
    _ptrCurrentState[xG + markerX][yG + markerY] = 1;
  }
  _ptrCurrentState[xG][yG] = 0;
}

// _____________________________________________________________________________

void GameOfLife::constructAcorn(int xG, int yG)  {
  int const (*ptrAcorn)[2] = _ACORN;
  int markerX = 0;
  int markerY = 0;
  for (int i=0; i < 7; i++) {
    markerX = ptrAcorn[i][0];
    markerY = ptrAcorn[i][1];
    _ptrCurrentState[xG + markerX][yG + markerY] = 1;
  }
  _ptrCurrentState[xG][yG] = 0;
}

