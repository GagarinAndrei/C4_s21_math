#include "s21_math.h"

long double s21_pow(double base, double exp) {
  if (exp == 0) return 1;
  if (base == 0) return 0;

  long double result = 1.0;

  if (exp == (long int)exp && exp > 0) {
    for (int i = 0; i < exp; i++) {
      result *= base;
    }
  } else {
    result = s21_exp(exp * s21_log(base));
  }

  return result;
}
