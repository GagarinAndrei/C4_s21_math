#include "../s21_math.h"

long double s21_atan(double x) {
  x = s21_asin(x / (s21_sqrt(1 + s21_pow(x, 2))));
  return x;
}
