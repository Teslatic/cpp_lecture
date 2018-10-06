// Copyright 2018, University of Freiburg,
// Author: Hendrik Vloet <vloett@informatik.uni-freiburg.de>

#include <ncurses.h>
#include <math.h>
#include <unistd.h>
#include "./Ball.h"


// here, stuff gets IMPLEMENTED


// _______________________________________________________________________
// Position
float x;
float y;
// Velocitiy
float vx;
float vy;
// Acceleration
float ax;
float ay;
// window limits
float maxX;
float maxY;
// Radius
int rx;
int ry;

// _______________________________________________________________________

void initTerminal() {
  initscr();
  cbreak();
  noecho();
  curs_set(false);
  nodelay(stdscr, true);
  keypad(stdscr, true);

  // draw something on screen
  maxX = COLS;
  maxY = LINES;
  x = 20;
  y = 10;
  rx = 10;
  ry = 5;
  vx = 2.0;
  vy = 0.1;

  ax = 0;
  ay = 0.1;
}


// _______________________________________________________________________

void drawFrame()  {
  attron(A_REVERSE);
  for (int frameX = 0; frameX <= COLS; frameX++) {
    mvprintw(0, frameX, " ");
    mvprintw(LINES - 1, frameX, " ");   // -1 for terminal line indexing
  }
  for (int frameY = 0; frameY <= LINES; frameY++) {
    mvprintw(frameY, 0, " ");
    mvprintw(frameY, COLS - 1, " ");  // -1 for terminal column indexing
  }
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

int moveBall(int key) {
  switch (key)  {
    case 27:
      return -1;
    case KEY_LEFT:
        vx -= 0.05;
        break;
    case KEY_RIGHT:
        vx += 0.05;
        break;
    case KEY_UP:
        ay -= 0.05;
        break;
    case KEY_DOWN:
        ay += 0.05;
        break;
  }

  float v = sqrt(vx * vx + vy * vy);
  x += vx / v;
  y += vy / v;
  vx += ax;
  vy += ay;

  if (x > maxX - rx  || x <=  rx)  {
    vx *= -0.9;
    vy *= 0.9;
    x = x <= rx ? rx : maxX- rx;
  }

  if (y > maxY - ry || y <= ry)  {
    vx *= 0.9;
    vy *= -0.9;
    y = y <= ry  ? ry : maxY - ry;
  }

  return v;
}
