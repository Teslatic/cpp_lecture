// Copyright 2018, University of Freiburg,
// Author: Hendrik Vloet <vloett@informatik.uni-freiburg.de>

#include <ncurses.h>
#include <unistd.h>

// _______________________________________________________________________
void initialize() {
  initscr();
  cbreak();
  noecho();
  curs_set(false);
  nodelay(stdscr, true);
  keypad(stdscr, true);

  // draw something on screen
  float changerate = 5;
  float x = COLS / 2;
  float y = LINES / 2;
  float rx = 10;
  float ry = 5;
}

// _______________________________________________________________________

void drawBall() {
  attron(A_REVERSE);
  for (int dx = -rx; dx <= rx; dx++)  {
    for (int dy = -ry; dy <= ry; dy++)  {
      if ( dx * dx * ry * ry + dy * dy * rx * rx < rx * rx * ry * ry) {
        mvprintw(y + dy, x + dx, " ");
      }
    }
  }
  attroff(A_REVERSE);
}

// _______________________________________________________________________
