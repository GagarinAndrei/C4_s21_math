#include "../s21_math.h"

long double s21_log(double x) {
  long double n = x;
  long long int copy_exp = 0;
  double result = 0;
  double compare;

  if (x == 0) {
    result = -S21_INF;
  } else if ((x != x) || x < 0) {
    result = S21_NAN;
  } else if (x == -S21_INF) {
    result = -S21_INF;
  } else {
    while (n >= S21_E) {
      n /= S21_E;
      copy_exp++;
    }
    for (int i = 0; i < 50; i++) {
      compare = result;
      result = compare + 2 * (n - s21_exp(compare)) / (n + s21_exp(compare));
    }
  }

  return result + copy_exp;
}

// int main() {

// 0.000001
//      printf("%Lf\n", s21_log(4.56));
//      printf("%f\n", log(4.56));
//      return 0;
//  }