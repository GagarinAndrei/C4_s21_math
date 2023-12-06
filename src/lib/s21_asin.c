#include <math.h>
#include <stdio.h>

#include "s21_math.h"

long double s21_asin(double x) {
  long double res = 0.0;
  if (s21_fabs(x) > 1 || x == S21_INF || x == -S21_INF) return S21_NAN;
  ;
  if (x == S21_NAN) return S21_NAN;
  if (x == 1) return S21_PI / 2;
  if (x == -1) return -S21_PI / 2;
  if (x == 0 || x == -0.0)
    return 0.0;
  else {
    double start_guess = 3 * x / (2 + s21_sqrt(1 - s21_pow(x, 2)));
    double prev_guess;
    prev_guess = start_guess;
    for (int i = 0; i < 100; i++) {
      res = prev_guess - (s21_sin(prev_guess) - x) / s21_cos(prev_guess);
      prev_guess = res;
    }
  }
  return res;
}
// int main(){
// printf("%Lf\n", s21_asin(0.9));
// printf("%f", asin(0.9));

//   return 0;
// }