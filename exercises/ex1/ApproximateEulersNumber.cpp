// Copyright 2018, University of Freiburg,
// Author: Hendrik Vloet <vloett@informatik.uni-freiburg.de>

// function approximates eulers number with taylor seris
float ApproximateEulersNumber(int n)  {
  float approx_euler = 0.0;
  float tmp_fak = 1.0;

  for (int k = 1; k <= n; k++) {
    approx_euler += tmp_fak;
    tmp_fak = tmp_fak * (1.0/k);
  }
return approx_euler;
}

// function approximates eulers number with numerical integration via trapezoid

float ApproximateEulersNumberIntegralMethod(int n) {
  float dx = (M_E - 1.0)/n;
  float integral;
  float x;
  float fx;
  float sum = 1.0;


  for (int k = 0; k <= n; k++)  {
    x = 1.0 + k * dx;
    fx = 1.0/x;
    if (( k == 0) || (k == n)) {
      sum +=  fx;
    } else  {
        sum += 2 * fx;
    }
  }
  integral = sum * (dx/2.0);

  return x;
}
