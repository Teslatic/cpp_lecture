// Copyright 2018, Hendrik Vloet & Chair of AD @ University of Freiburg
// Author: Hendrik Vloet <hendrik.vloet@gmx.de>
// Using various code snippets kindly provided by
// http://ad-wiki.informatik.uni-freiburg.de/teaching

#include <stdio.h>
#include "./GameOfLife.h"
#include <ncurses.h>

int main(int argc, char **argv)  {
  GameOfLife game;
  game.play();
}
