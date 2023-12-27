
#include "../s21_math.h"
int s21_factorial(int n) {
  if (n < 0) {
    return S21_NAN;
  }
  if (n == 1 || n == 0) {
    return 1;
  } else
    return s21_factorial((n - 1)) * n;
}
