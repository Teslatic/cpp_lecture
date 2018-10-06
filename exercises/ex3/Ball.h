// Copyright 2018, University of Freiburg,
// Author: Hendrik Vloet <vloett@informatik.uni-freiburg.de>

// here, stuff gets only DECLARED

#ifndef BALL_H_
#define BALL_H_

// position and radii
extern int changerate;
extern float x;
extern float y;
extern float vx;
extern float vy;
extern float ax;
extern float ay;
extern float maxX;
extern float maxY;
extern int rx;
extern int ry;

// gravitational accelaration
extern float g;



// initialize screen and global variables
void initTerminal();

// draw ball
void drawBall();

// draw frame
void drawFrame();

// move ball position according to lecture
// void moveBallLecture(int key = KEY_F0);

// move ball according to exercise
int moveBall(int key = KEY_F0);

#endif  // BALL_H_
