#include "s21_math.h"

int s21_abs(int x) { return (x < 0) ? x *= -1 : x; }

long double s21_acos(double x) {
  if (x > 1 || x < -1) return S21_NAN;
  return S21_PI / 2 - s21_asin(x);
}

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

long double s21_atan(double x) {
  x = s21_asin(x / (s21_sqrt(1 + s21_pow(x, 2))));
  return x;
}

long double s21_ceil(double x) {
  if (x == -0.0) return x;

  return (x < 0 || x == (int)x) ? (int)x : (int)x + 1;
}

long double s21_cos(double x) { return s21_sin(x + S21_PI / 2); }

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

long double s21_fabs(double x) { return (x >= 0) ? x : -x; }

long double s21_floor(double x) {
  if (x == -0.0) return x;
  return (x < 0 && x != (int)x) ? (int)x - 1 : (int)x;
}

long double s21_fmod(double x, double y) {
  if (y == 0.0 || y == -0.0) return S21_NAN;

  long double result = 0.0;
  int n = 0;
  if (y != 0) {
    n = x / y;
    result = x - n * y;
  }
  return (x < 0 && result == 0) ? -result : result;
}

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

long double s21_sin(double x) {
  while (s21_fabs(x) - 2 * S21_PI > 0) {
    x += 2 * S21_PI * x / s21_fabs(x) * -1;
  }
  long double result = 0;
  int singularity = 1;
  double xx = x * x;
  double p_x = x;
  double factorial = 1.0;
  for (int i = 1; i < 200; i += 2) {
    factorial *= i;
    result += singularity * p_x / factorial;
    factorial *= (i + 1);
    singularity = -singularity;
    p_x *= xx;
  }
  return result;
}

long double s21_sqrt(double x) { return s21_pow(x, 0.5); }

long double s21_tan(double x) { return s21_sin(x) / s21_cos(x); }

int s21_factorial(int n) {
  if (n < 0) {
    return S21_NAN;
  }
  if (n == 1 || n == 0) {
    return 1;
  } else
    return s21_factorial((n - 1)) * n;
}