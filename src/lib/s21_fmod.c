#include "s21_math.h"

long double s21_fmod(double x, double y) {  // готово
  long double result = 0.0;
  int n = 0;
  if (y != 0) {
    n = x / y;
    result = x - n * y;
  }
  return (x < 0 && result == 0) ? -result : result;
}
