// Copyright 2018, University of Freiburg,
// Author: Hendrik Vloet <vloett@informatik.uni-freiburg.de>

#include <ncurses.h>
#include <unistd.h>
#include "./Ball.h"


// here, stuff gets IMPLEMENTED


// _______________________________________________________________________
int changerate;
int x;
int y;
int rx;
int ry;

// _______________________________________________________________________
void initialize() {
  initscr();
  cbreak();
  noecho();
  curs_set(false);
  nodelay(stdscr, true);
  keypad(stdscr, true);

  // draw something on screen
  changerate = 5;
  x = COLS / 2;
  y = LINES / 2;
  rx = 10;
  ry = 5;
}

// _______________________________________________________________________

void drawBall() {
  attron(A_REVERSE);
  for (int dx = -rx; dx <= rx; dx++)  {
    for (int dy = -ry; dy <= ry; dy++)  {
      if (dx * dx * ry * ry + dy * dy * rx * rx < rx * rx * ry * ry) {
        mvprintw(y + dy, x + dx, " ");
      }
    }
  }
  attroff(A_REVERSE);
}

// _______________________________________________________________________
