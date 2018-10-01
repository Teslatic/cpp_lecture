// Copyright 2018, University of Freiburg,
// Author: Hendrik Vloet <vloett@informatik.uni-freiburg.de>

// here, stuff gets only DECLARED

#ifndef BALL_H_
#define BALL_H_

// position and radii
extern int changerate;
extern int x;
extern int y;
extern int rx;
extern int ry;

// initialize screen and global variables
void initialize();

// draw ball
void drawBall();

#endif  // BALL_H_
