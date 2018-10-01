// Copyright 2018, University of Freiburg,
// Chair of Algorithms and Data Structures.
// Author: Hendrik Vloet <vloett@informatik.uni-freiburg.de>

int approxPiCircleMethod(int n) {
  int count = 0;
  for (int x = -n; x <= n; x++) {
    for (int y = -n; y <= n; y++)  {
      if (x*x + y * y <= n*n) {
        count++;
      }
    }
  }
  return count;
}
