// Copyright 2018, Hendrik Vloet
// Author: Hendrik Vloet <vloett@informatik.uni-freiburg.de>

#include <ncurses.h>
#include <stdio.h>




int main(int argc, char** argv) {
  initscr();
  cbreak();
  noecho();
  curs_set(false);
  nodelay(stdscr, true);
  keypad(stdscr, true);
  mousemask(ALL_MOUSE_EVENTS, NULL);

  // cells ( 0 = false)
  const int MAX = 200;
  bool cells[MAX][MAX] = { 0 };



  // check for mouse clicks and get coordinates
  while (true)  {
    MEVENT event;           // MEVENT is a struct
    int key = getch();
    if (key == KEY_MOUSE) {
      if (getmouse(&event) == OK && event.bstate & BUTTON1_CLICKED) {
        int x = event.x;
        int y = event.y;
        mvprintw(0, 0, "Mouse clicked at %d, %d\n", x, y);
        cells[x][y] = !cells[x][y];
        if (cells[x][y] == true)  { attron(A_REVERSE);
          mvprintw(y, x, " ");
          attroff(A_REVERSE);
        }
        refresh();
      }
    }
  }

  // clean up
  endwin();
}
