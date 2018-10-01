// Copyright 2018, University of Freiburg,
// Author: Hendrik Vloet <vloett@informatik.uni-freiburg.de>

#include <ncurses.h>
#include <unistd.h>
#include "./Ball.h"

// Show a ball on the screen controlled by the arrow keys
int main(int argc, char** argv) {
  initialize();
  while (true)  {
    drawBall();
    refresh();
    int key = getch();
    switch (key)  {
      case KEY_LEFT:
        x -= changerate;
        break;
      case KEY_RIGHT:
        x += changerate;
        break;
      case KEY_UP:
        y -= changerate;
        break;
      case KEY_DOWN:
        y += changerate;
        break;
    }
    usleep(20*1000);
    clear();
  }



  // cleanup
  endwin();
}
