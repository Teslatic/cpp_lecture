// Copyright 2018, University of Freiburg,
// Author: Hendrik Vloet <vloett@informatik.uni-freiburg.de>

#include <ncurses.h>
#include <unistd.h>
#include "./Ball.h"

// Show a ball on the screen controlled by the arrow keys
int main(int argc, char** argv) {
  initTerminal();
  while (true)  {
    drawBall();
    // drawFrame();
    refresh();

    int key = getch();

    // moveBallLecture(key);
    float velocity = moveBall(key);

    if (velocity == -1) {
      break;
    }


    usleep((1 / velocity) *10000);
    clear();
  }



  // cleanup
  endwin();
}
