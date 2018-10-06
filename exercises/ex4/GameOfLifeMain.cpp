// Copyright 2018, Hendrik Vloet
// Author: Hendrik Vloet <vloett@informatik.uni-freiburg.de>

#include <ncurses.h>
#include <stdio.h>
#include <unistd.h>
#include "./GameOfLife.h"

int main(int argc, char** argv) {
  initTerminal();
  bool first = 1;
  bool toggleProb = 1;
    while (true)  {
      // force pause on beginning to make direct manual setup possible
      if (first == 1)  {
        processedInput = 2;
        first = !first;
      } else  {
        processedInput = processUserInput();
      }
      switch (processedInput) {
        // space pressed
        case 2:
          while (true)  {
            showState();
            processedInput = processUserInput();
            // space pressed
            if (processedInput == 2)  {
              break;
            }
            // s pressed
            if (processedInput == 1)  {
              updateState();
            }
            if (processedInput == 3)  {
              constructGlider(x, y);
            }
            if (processedInput == 4)  {
              constructGliderFactory(x, y);
            }
            if (processedInput == 5)  {
              constructAcorn(x, y);
            }
            if (processedInput == 6)  {
              if (toggleProb == 1)  {
                p = 0.2;
              } else  {
                p = 1.0;
              }
              toggleProb = !toggleProb;
            }
            // ESC pressed
            if (processedInput == -1) {
              break;
            }
          }
          break;
        case 3:
          constructGlider(x, y);
          break;
        case 4:
          constructGliderFactory(x, y);
          break;
        case 5:
          constructAcorn(x, y);
          break;
        case -1:
          break;
        default:
          showState();
          updateState();
      }
      if (processedInput == -1) {
        break;
      }
}
  // clean up
  endwin();
}
