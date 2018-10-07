// Copyright 2018, Hendrik Vloet
// Author: Hendrik Vloet <vloett@informatik.uni-freiburg.de>

#include <ncurses.h>
#include <unistd.h>
#include "./GameOfLife.h"

int step = 1;
int x;
int y;
int processedInput = 0;
float p = 1.0;

// bool currentState[MAX_GRID_SIZE][MAX_GRID_SIZE] = { 0 };
// bool nextState[MAX_GRID_SIZE][MAX_GRID_SIZE] = { 0 };

bool GameOfLife::_ptrCurrentState = _currentState;
bool GameOfLife::_ptrNextStat = _NextState;
// bool (*ptrNextState)[MAX_GRID_SIZE] = nextState;

// __________________________________________________________________________
void initTerminal() {
  initscr();
  cbreak();
  noecho();
  curs_set(false);
  nodelay(stdscr, true);
  keypad(stdscr, true);
  mousemask(ALL_MOUSE_EVENTS, NULL);
}

// __________________________________________________________________________
void showState()  {
  int population = 0;
  for (int j = GRID_START; j <= MAX_GRID_SIZE; j++) {
    for (int k = 0; k <= MAX_GRID_SIZE; k++) {
      if (ptrCurrentState[k][j] == 1)  {
        population++;
        attron(A_REVERSE);
        mvprintw(j, k, " ");
        attroff(A_REVERSE);
      } else  {
        mvprintw(j, k, " ");
      }
    }
  }
  mvprintw(0, 0, "Generation: %d", step);
  mvprintw(1, 0, "Population: %d", population);
  mvprintw(2, 0, "probability: %1.1f", p);
  refresh();
  usleep(10 * 1000);
}

void constructGlider(int xG, int yG)  {
  int const (*ptrGlider)[2] = GLIDER;
  int markerX = 0;
  int markerY = 0;
  for (int i=0; i < 5; i++) {
    markerX = ptrGlider[i][0];
    markerY = ptrGlider[i][1];
    ptrCurrentState[xG + markerX][yG + markerY] = 1;
  }
  ptrCurrentState[xG][yG] = 0;
}

void constructGliderFactory(int xG, int yG)  {
  int const (*ptrGliderFactory)[2] = FACTORY;
  int markerX = 0;
  int markerY = 0;
  for (int i=0; i < 36; i++) {
    markerX = ptrGliderFactory[i][0];
    markerY = ptrGliderFactory[i][1];
    ptrCurrentState[xG + markerX][yG + markerY] = 1;
  }
  ptrCurrentState[xG][yG] = 0;
}

void constructAcorn(int xG, int yG)  {
  int const (*ptrAcorn)[2] = ACORN;
  int markerX = 0;
  int markerY = 0;
  for (int i=0; i < 7; i++) {
    markerX = ptrAcorn[i][0];
    markerY = ptrAcorn[i][1];
    ptrCurrentState[xG + markerX][yG + markerY] = 1;
  }
  ptrCurrentState[xG][yG] = 0;
}


int aliveNeighbours(int l, int k) {
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
    case MAX_GRID_SIZE:
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
    case MAX_GRID_SIZE:
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
      if (ptrCurrentState[n][m] == 1) {
        healthyNeighbours++;
      }
    }
  }
  // alive center cell should not count as neighbour
  if (ptrCurrentState[l][k] == 1) {
    healthyNeighbours--;
  }
  return healthyNeighbours;
}

void updateState()  {
  int livingNeighbours = 0;
  // loop over whole grid
  for (int k = GRID_START; k <= MAX_GRID_SIZE; k++) {
    for (int l = 0; l <= MAX_GRID_SIZE; l++) {
      livingNeighbours = aliveNeighbours(l, k);
      // dead cell rules
      if (ptrCurrentState[l][k] == 0)  {
        // cell comes to live
        if (livingNeighbours == 3)  {
          ptrNextState[l][k] = 1;
        } else  {
          ptrNextState[l][k] = 0;
        }
      } else  {
        if (livingNeighbours == 3 || livingNeighbours == 2)  {
          // cell survives
          ptrNextState[l][k] = 1;
        } else  {
          ptrNextState[l][k] = 0;
          }
        }
      }
    }
  ptrNextState = (step % 2 == 0) ? currentState : nextState;
  ptrCurrentState = (step % 2 == 0) ?  nextState : currentState;
  step++;
}

int processUserInput() {
  int key = getch();
  usleep(50 * 1000);
  switch (key)  {
    case KEY_MOUSE:
    MEVENT event;           // MEVENT is a struct
    if (getmouse(&event) == OK && event.bstate & BUTTON1_CLICKED) {
      x = event.x;
      y = event.y;
      ptrCurrentState[x][y] = !ptrCurrentState[x][y];
      return 0;
    }
    case 's':   // make one step while in pause mode
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
