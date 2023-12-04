#include "s21_math.h"

long double s21_floor(double x) {
  if (x == -0.0) return x;
  return (x < 0 && x != (int)x) ? (int)x - 1 : (int)x;
}  //готово
