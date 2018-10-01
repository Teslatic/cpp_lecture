// Copyright 2018, University of Freiburg,
// Author: Hendrik Vloet <vloett@informatik.uni-freiburg.de>

#include <stdio.h>
#include "./ApproximateEulersNumber.h"

int main(int argc, char** argv) {
  int n = 10;
  float euler = ApproximateEulersNumber(n);
  float euler_integral = ApproximateEulersNumberIntegralMethod(n);
  printf("Eulers no. with Taylor series:     %1.10f\n", euler);
  printf("Eulers no. with integral method:   %1.10f\n", euler_integral);
}
