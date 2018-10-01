// Copyright 2018, University of Freiburg,
// Chair of Algorithms and Data Structures.
// Author: Hendrik Vloet <vloett@informatik.uni-freiburg.de>

#include <stdio.h>
#include <math.h>
#include "./approx_pi.cpp"

int main(int argc, char** argv) {
  int n = 10000;
  int count = approxPiCircleMethod(n);
  int numGridPoints = (2*n + 1) * (2*n+1);
  printf("\n");
  printf("Dimension of the grid     : [-%d, +%d] x [-%d, +%d]\n", n, n, n, n);
  printf("Number of grid points     : %d\n", numGridPoints);
  printf("Number of points in circle: %d\n", count);
  printf("Approx. of Pi             : %1.10f\n" , 4.0 * count / numGridPoints);
  printf("Internal value of Pi      : %1.10f\n", M_PI);
  printf("\n");
}
