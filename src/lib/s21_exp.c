#include "../s21_math.h"

long double s21_exp(double x) {
  if (x < 0) return 0.0;
  long double taylor_series = 1;
  long double result = 1;
  long double i = 1;
  while (s21_fabs(taylor_series) > ACCUR) {
    taylor_series *= x / i;
    i++;
    result += taylor_series;
  }
  return result;
}
