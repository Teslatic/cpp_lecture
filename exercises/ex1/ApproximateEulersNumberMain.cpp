// Copyright 2018, University of Freiburg,
// Author: Hendrik Vloet <vloett@informatik.uni-freiburg.de>

#include <stdio.h>
#include <math.h>
#include "./ApproximateEulersNumber.cpp"
int main(int argc, char** argv) {
  int n = 10;
  float euler = ApproximateEulersNumber(n);
  float euler_integral = ApproximateEulersNumberIntegralMethod(n);
  printf("Approximation for Eulers Number: %1.10f\n", euler);
  printf("Approximation for Eulers Number with integral method: \
    %1.20f\n", euler_integral);
}
