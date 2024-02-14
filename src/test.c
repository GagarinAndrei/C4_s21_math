#include <check.h>
#include <math.h>
#include <stdlib.h>

#include "s21_math.h"

#define EPSILON 1e-37
#define PRECISION 1000
#define ACCU 1e-6

#define INT_MIN -2147483648
#define INT_MAX +2147483647
#define S21_LDBL_MAX 1.18973e+4932L
#define S21_LDBL_MIN 3.3621e-4932L

#define S21_NAN (0.0 / 0.0)
#define S21_INFINITY (1.0 / 0.0)

// #define S21_E 2.71828182845904523536L
#define S21_LOG2E 1.44269504088896340736L
#define S21_LOG10E 0.434294481903251827651L
#define S21_LN2 0.693147180559945309417L
#define S21_LN10 2.30258509299404568402L

// #define S21_PI 3.14159265358979323846L
#define S21_PI_2 1.57079632679489661923L
#define S21_PI_4 0.785398163397448309616L
#define S21_1_PI 0.318309886183790671538L
#define S21_2_PI 0.636619772367581343076L

#define S21_2_SQRTPI 1.12837916709551257390L
#define S21_SQRT2 1.41421356237309504880L
#define S21_SQRT1_2 0.707106781186547524401L

START_TEST(floor_1) {
  double x = 0;
  ck_assert_double_eq_tol(floor(x), s21_floor(x), ACCU);
}
END_TEST

START_TEST(floor_2) {
  double x = S21_INFINITY;
  ck_assert_double_infinite(s21_floor(x));
}
END_TEST

START_TEST(floor_3) {
  double x = -S21_INFINITY;
  ck_assert_double_infinite(s21_floor(x));
}
END_TEST

START_TEST(floor_4) {
  double x = 2.5;
  ck_assert_double_eq_tol(floor(x), s21_floor(x), ACCU);
}
END_TEST

START_TEST(floor_5) {
  double x = -2.5;
  ck_assert_double_eq_tol(floor(x), s21_floor(x), ACCU);
}
END_TEST

START_TEST(floor_6) {
  double x = S21_LDBL_MAX;
  ck_assert_double_infinite(s21_floor(x));
}
END_TEST

START_TEST(floor_7) {
  double x = S21_LDBL_MIN;
  ck_assert_double_eq_tol(floor(x), s21_floor(x), ACCU);
}
END_TEST

START_TEST(floor_8) {
  double x = NAN;
  ck_assert_double_nan(s21_floor(x));
}
END_TEST

START_TEST(floor_9) {
  double x = -7.0;
  ck_assert_double_eq_tol(floor(x), s21_floor(x), ACCU);
}
END_TEST

START_TEST(floor_10) {
  double x = -98.1;
  ck_assert_double_eq_tol(floor(x), s21_floor(x), ACCU);
}
END_TEST

START_TEST(floor_11) {
  double x = 123.02;
  ck_assert_double_eq_tol(floor(x), s21_floor(x), ACCU);
}
END_TEST

START_TEST(floor_12) {
  double x = 10009.00123;
  ck_assert_double_eq_tol(floor(x), s21_floor(x), ACCU);
}
END_TEST

START_TEST(floor_13) {
  double x = -10009.00123;
  ck_assert_double_eq_tol(floor(x), s21_floor(x), ACCU);
}
END_TEST

START_TEST(floor_14) {
  double x = -0.10009;
  ck_assert_double_eq_tol(floor(x), s21_floor(x), ACCU);
}
END_TEST

START_TEST(floor_15) {
  double x = -10009.00123;
  ck_assert_double_eq_tol(floor(x), s21_floor(x), ACCU);
}
END_TEST

START_TEST(floor_16) {
  double x = -10009.555;
  ck_assert_double_eq_tol(floor(x), s21_floor(x), ACCU);
}
END_TEST

START_TEST(floor_17) {
  double x = -1e-23;
  ck_assert_double_eq_tol(floor(x), s21_floor(x), ACCU);
}
END_TEST

START_TEST(floor_18) {
  double x = 100091234.5;
  ck_assert_double_eq_tol(floor(x), s21_floor(x), ACCU);
}
END_TEST

START_TEST(fmod1) {
  double x = 0.0, y = 0.0;
  ck_assert_double_nan(s21_fmod(x, y));
}
END_TEST

START_TEST(fmod2) {
  double x = 1.0, y = S21_NAN;
  ck_assert_double_nan(s21_fmod(x, y));
}
END_TEST

START_TEST(fmod3) {
  double x = S21_NAN, y = 1.0;
  ck_assert_double_nan(s21_fmod(x, y));
}
END_TEST

START_TEST(fmod4) {
  double x = S21_INFINITY, y = 1.0;
  ck_assert_double_nan(s21_fmod(x, y));
}
END_TEST

START_TEST(fmod5) {
  double x = 1.0, y = S21_INFINITY;
  ck_assert_double_eq_tol(fmod(x, y), s21_fmod(x, y), ACCU);
}
END_TEST

START_TEST(fmod6) {
  double x = 0.0, y = S21_INFINITY;
  ck_assert_double_eq_tol(fmod(x, y), s21_fmod(x, y), ACCU);
}
END_TEST

START_TEST(fmod7) {
  double x = S21_INFINITY, y = S21_INFINITY;
  ck_assert_double_nan(s21_fmod(x, y));
}
END_TEST

START_TEST(fmod8) {
  double x = 1.0, y = 0.5;
  ck_assert_double_eq_tol(fmod(x, y), s21_fmod(x, y), ACCU);
}
END_TEST

START_TEST(fmod9) {
  double x = 199999.00005, y = 5.0;
  ck_assert_double_eq_tol(fmod(x, y), s21_fmod(x, y), ACCU);
}
END_TEST

START_TEST(fmod10) {
  double x = 199999.00005, y = S21_INFINITY;
  ck_assert_double_eq_tol(fmod(x, y), s21_fmod(x, y), ACCU);
}
END_TEST

START_TEST(ceil1) {
  double x = 0.0;
  ck_assert_double_eq_tol(ceil(x), s21_ceil(x), ACCU);
}
END_TEST

START_TEST(ceil2) {
  double x = S21_INFINITY;
  ck_assert_float_infinite(ceil(x));
}
END_TEST

START_TEST(ceil3) {
  double x = -S21_INFINITY;
  ck_assert_float_infinite(ceil(x));
}
END_TEST

START_TEST(ceil4) {
  double x = 0.6;
  ck_assert_double_eq_tol(ceil(x), s21_ceil(x), ACCU);
}
END_TEST

START_TEST(ceil5) {
  double x = S21_LDBL_MAX;
  ck_assert_float_infinite(ceil(x));
}
END_TEST

START_TEST(ceil6) {
  double x = S21_LDBL_MIN;
  ck_assert_double_eq_tol(ceil(x), s21_ceil(x), ACCU);
}
END_TEST

START_TEST(ceil7) {
  double x = S21_NAN;
  ck_assert_float_nan(s21_ceil(x));
}
END_TEST

START_TEST(ceil8) {
  double x = -7.0;
  ck_assert_double_eq_tol(ceil(x), s21_ceil(x), ACCU);
}
END_TEST

START_TEST(ceil9) {
  double x = -98.1;
  ck_assert_double_eq_tol(ceil(x), s21_ceil(x), ACCU);
}
END_TEST

START_TEST(ceil10) {
  double x = 123.02;
  ck_assert_double_eq_tol(ceil(x), s21_ceil(x), ACCU);
}
END_TEST

START_TEST(ceil11) {
  double x = 10009.00123;
  ck_assert_double_eq_tol(ceil(x), s21_ceil(x), ACCU);
}
END_TEST

START_TEST(ceil12) {
  double x = -10009.555;
  ck_assert_double_eq_tol(ceil(x), s21_ceil(x), ACCU);
}
END_TEST

START_TEST(ceil13) {
  double x = -0.10009;
  ck_assert_double_eq_tol(ceil(x), s21_ceil(x), ACCU);
}
END_TEST

START_TEST(ceil14) {
  double x = -1e-23;
  ck_assert_double_eq_tol(ceil(x), s21_ceil(x), ACCU);
}
END_TEST

START_TEST(ceil15) {
  double x = S21_INFINITY;
  ck_assert_double_infinite(s21_ceil(x));
}
END_TEST

START_TEST(ceil16) {
  double x = -S21_INFINITY;
  ck_assert_double_infinite(s21_ceil(x));
}
END_TEST

START_TEST(abs1) {
  int x = -7.0;
  ck_assert_int_eq(abs(x), s21_abs(x));
}
END_TEST

START_TEST(abs2) {
  int x = -98;
  ck_assert_int_eq(abs(x), s21_abs(x));
}
END_TEST

START_TEST(abs3) {
  int x = 123;
  ck_assert_int_eq(abs(x), s21_abs(x));
}
END_TEST

START_TEST(abs4) {
  int x = 10009;
  ck_assert_int_eq(abs(x), s21_abs(x));
}
END_TEST

START_TEST(abs5) {
  int x = -10009;
  ck_assert_int_eq(abs(x), s21_abs(x));
}
END_TEST

START_TEST(abs6) {
  int x = INT_MAX;
  ck_assert_int_eq(abs(x), s21_abs(x));
}
END_TEST

START_TEST(abs7) {
  int x = INT_MIN;
  ck_assert_int_eq(abs(x), s21_abs(x));
}
END_TEST

START_TEST(fabs1) {
  double x = 0.0;
  ck_assert_double_eq_tol(fabs(x), s21_fabs(x), ACCU);
}
END_TEST

START_TEST(fabs2) {
  double x = S21_INFINITY;
  ck_assert_float_infinite(s21_fabs(x));
}
END_TEST

START_TEST(fabs3) {
  double x = -S21_INFINITY;
  ck_assert_float_infinite(s21_fabs(x));
}
END_TEST

START_TEST(fabs4) {
  double x = -10;
  ck_assert_double_eq_tol(fabs(x), s21_fabs(x), ACCU);
}
END_TEST

START_TEST(fabs5) {
  double x = -10.23;
  ck_assert_double_eq_tol(fabs(x), s21_fabs(x), ACCU);
}
END_TEST

START_TEST(fabs6) {
  double x = S21_LDBL_MAX;
  ck_assert_float_infinite(s21_fabs(x));
}
END_TEST

START_TEST(fabs7) {
  double x = S21_LDBL_MIN;
  ck_assert_double_eq_tol(fabs(x), s21_fabs(x), ACCU);
}
END_TEST

START_TEST(fabs8) {
  double x = S21_NAN;
  ck_assert_float_nan(s21_fabs(x));
}
END_TEST

START_TEST(fabs9) {
  double x = -7.0;
  ck_assert_double_eq_tol(fabs(x), s21_fabs(x), ACCU);
}
END_TEST

START_TEST(fabs10) {
  double x = -98.1;
  ck_assert_double_eq_tol(fabs(x), s21_fabs(x), ACCU);
}
END_TEST

START_TEST(fabs11) {
  double x = 123.02;
  ck_assert_double_eq_tol(fabs(x), s21_fabs(x), ACCU);
}
END_TEST

START_TEST(fabs12) {
  double x = 10009.0;
  ck_assert_double_eq_tol(fabs(x), s21_fabs(x), ACCU);
}
END_TEST

START_TEST(fabs13) {
  double x = -10009.555;
  ck_assert_double_eq_tol(fabs(x), s21_fabs(x), ACCU);
}
END_TEST

START_TEST(fabs14) {
  double x = -0.10009;
  ck_assert_double_eq_tol(fabs(x), s21_fabs(x), ACCU);
}
END_TEST

START_TEST(fabs15) {
  double x = -1e23;
  ck_assert_double_eq_tol(fabs(x), s21_fabs(x), ACCU);
}
END_TEST

START_TEST(exp1) {
  int x = 0.0;
  ck_assert_double_eq_tol(exp(x), s21_exp(x), ACCU);
}
END_TEST

START_TEST(exp_2) {
  long double x = -S21_INFINITY;
  ck_assert_double_eq_tol(exp(x), s21_exp(x), ACCU);
}
END_TEST

START_TEST(exp3) {
  long double x = S21_INFINITY;
  ck_assert_float_infinite(s21_exp(x));
}
END_TEST

START_TEST(exp4) {
  long double x = 10.0;
  ck_assert_double_eq_tol(exp(x), s21_exp(x), ACCU);
}
END_TEST

START_TEST(exp5) {
  long double x = 101.0;
  ck_assert_float_infinite(s21_exp(x));
}
END_TEST

START_TEST(exp6) {
  long double x = S21_LDBL_MAX;
  ck_assert_float_infinite(s21_exp(x));
}
END_TEST

START_TEST(exp7) {
  long double x = S21_LDBL_MIN;
  ck_assert_double_eq_tol(exp(x), s21_exp(x), ACCU);
}
END_TEST

START_TEST(exp8) {
  long double x = S21_NAN;
  ck_assert_float_nan(s21_exp(x));
}
END_TEST

START_TEST(exp9) {
  long double x = S21_NAN;
  ck_assert_float_nan(s21_exp(x));
}
END_TEST

START_TEST(exp10) {
  for (double i = -21; i < 21; i += 1) {
    double a = s21_exp(i);
    double b = exp(i);
    ck_assert_double_eq_tol(a, b, ACCU);
  }
}
END_TEST

START_TEST(exp11) {
  for (double i = -15; i < 15; i += 0.123) {
    double a = s21_exp(i);
    double b = exp(i);
    ck_assert_double_eq_tol(a, b, ACCU);
  }
}
END_TEST

START_TEST(exp12) {
  for (double i = -5; i < 5; i += 0.00573) {
    double a = s21_exp(i);
    double b = exp(i);
    ck_assert_double_eq_tol(a, b, ACCU);
  }
}
END_TEST

START_TEST(exp13) {
  double x = 1;
  ck_assert_double_eq_tol(exp(x), s21_exp(x), ACCU);
}

END_TEST

START_TEST(exp14) {
  double x = -1;
  ck_assert_double_eq_tol(exp(x), s21_exp(x), ACCU);
}

END_TEST

START_TEST(exp15) {
  double x = 999999999999;
  ck_assert_double_infinite(s21_exp(x));
}

END_TEST

START_TEST(log1) {
  long double x = 0.0;
  ck_assert_float_infinite(s21_log(x));
}
END_TEST

START_TEST(log_2) {
  long double x = 1.0;
  ck_assert_double_eq_tol(log(x), s21_log(x), ACCU);
}
END_TEST

START_TEST(log3) {
  long double x = -2.0;
  ck_assert_double_nan(s21_log(x));
}
END_TEST

START_TEST(log4) {
  long double x = S21_INFINITY;
  ck_assert_float_infinite(s21_log(x));
}
END_TEST

START_TEST(log5) {
  long double x = 10;
  ck_assert_double_eq_tol(log(x), s21_log(x), ACCU);
}
END_TEST

START_TEST(log6) {
  long double x = -10;
  ck_assert_double_nan(s21_log(x));
}
END_TEST

START_TEST(log7) {
  long double x = S21_LDBL_MAX;
  ck_assert_float_infinite(s21_log(x));
}
END_TEST

START_TEST(log8) {
  long double x = S21_LDBL_MIN;
  ck_assert_float_infinite(s21_log(x));
}
END_TEST

START_TEST(log9) {
  long double x = S21_NAN;
  ck_assert_double_nan(s21_log(x));
}
END_TEST

START_TEST(log_10) {
  long double x = 2;
  ck_assert_double_eq_tol(log(x), s21_log(x), ACCU);
}
END_TEST

START_TEST(log11) {
  long double x = 3;
  ck_assert_double_eq_tol(log(x), s21_log(x), ACCU);
}
END_TEST

START_TEST(log12) {
  for (double i = 0.000005; i < 1; i *= 5) {
    double a = s21_log(i);
    double b = log(i);
    ck_assert_double_eq_tol(a, b, ACCU);
  }
}
END_TEST

START_TEST(log13) {
  for (double i = 0.1; i < 1000; i += 123) {
    double a = s21_log(i);
    double b = log(i);
    ck_assert_double_eq_tol(a, b, ACCU);
  }
}
END_TEST

START_TEST(log14) {
  for (double i = 0.1; i < 4; i += 0.24) {
    double a = s21_log(i);
    double b = log(i);
    ck_assert_double_eq_tol(a, b, ACCU);
  }
}
END_TEST

START_TEST(log15) {
  for (double i = 1; i < 100; i += 13.2) {
    double a = s21_log(i);
    double b = log(i);
    ck_assert_double_eq_tol(a, b, ACCU);
  }
}
END_TEST

START_TEST(pow1) {
  long double x = 0.0, y = 0.0;
  ck_assert_double_eq_tol(pow(x, y), s21_pow(x, y), ACCU);
}
END_TEST

START_TEST(pow2) {
  long double x = 0.0, y = -2.0;
  ck_assert_float_infinite(s21_pow(x, y));
}
END_TEST

START_TEST(pow3) {
  long double x = 0.0, y = 5.0;
  ck_assert_double_eq_tol(pow(x, y), s21_pow(x, y), ACCU);
}
END_TEST

START_TEST(pow4) {
  long double x = 0.0, y = 2.0;
  ck_assert_double_eq_tol(pow(x, y), s21_pow(x, y), ACCU);
}
END_TEST

START_TEST(pow5) {
  long double x = -1.0, y = S21_INFINITY;
  ck_assert_double_eq_tol(pow(x, y), s21_pow(x, y), ACCU);
}
END_TEST

START_TEST(pow6) {
  long double x = -1.0, y = -S21_INFINITY;
  ck_assert_double_eq_tol(pow(x, y), s21_pow(x, y), ACCU);
}
END_TEST

START_TEST(pow7) {
  long double x = -1.0, y = 0.5;
  ck_assert_float_nan(s21_pow(x, y));
}
END_TEST

START_TEST(pow8) {
  long double x = 0.5, y = -S21_INFINITY;
  ck_assert_float_infinite(s21_pow(x, y));
}
END_TEST

START_TEST(pow9) {
  long double x = -2, y = -S21_INFINITY;
  ck_assert_double_eq_tol(pow(x, y), s21_pow(x, y), ACCU);
}
END_TEST

START_TEST(pow10) {
  long double x = 0.5, y = S21_INFINITY;
  ck_assert_double_eq_tol(pow(x, y), s21_pow(x, y), ACCU);
}
END_TEST

START_TEST(pow11) {
  long double x = 3, y = S21_INFINITY;
  ck_assert_float_infinite(s21_pow(x, y));
}
END_TEST

START_TEST(pow12) {
  long double x = -S21_INFINITY, y = -1.0;
  ck_assert_double_eq_tol(pow(x, y), s21_pow(x, y), ACCU);
}
END_TEST

START_TEST(pow13) {
  long double x = -S21_INFINITY, y = -2.0;
  ck_assert_double_eq_tol(pow(x, y), s21_pow(x, y), ACCU);
}
END_TEST

START_TEST(pow14) {
  long double x = -S21_INFINITY, y = 3.0;
  ck_assert_float_infinite(s21_pow(x, y));
}
END_TEST

START_TEST(pow15) {
  long double x = -S21_INFINITY, y = 2.0;
  ck_assert_float_infinite(s21_pow(x, y));
}
END_TEST

START_TEST(pow16) {
  long double x = S21_INFINITY, y = -2.0;
  ck_assert_double_eq_tol(pow(x, y), s21_pow(x, y), ACCU);
}
END_TEST

START_TEST(pow17) {
  long double x = S21_INFINITY, y = 5.0;
  ck_assert_float_infinite(s21_pow(x, y));
}
END_TEST

START_TEST(pow18) {
  long double x = 10.0, y = -10.0;
  ck_assert_double_eq_tol(pow(x, y), s21_pow(x, y), ACCU);
}
END_TEST

START_TEST(pow19) {
  long double x = 100.0, y = 2.0;
  ck_assert_double_eq_tol(pow(x, y), s21_pow(x, y), ACCU);
}
END_TEST

START_TEST(pow20) {
  long double x = 0.0, y = -1.1;
  ck_assert_float_infinite(s21_pow(x, y));
}
END_TEST

START_TEST(pow21) {
  long double x = S21_LDBL_MAX, y = -1.1;
  ck_assert_double_eq_tol(pow(x, y), s21_pow(x, y), ACCU);
}
END_TEST

START_TEST(pow22) {
  long double x = S21_LDBL_MIN, y = -1.1;
  ck_assert_float_infinite(s21_pow(x, y));
}
END_TEST

START_TEST(pow23) {
  long double x = 1.0, y = 1.0;
  ck_assert_double_eq_tol(pow(x, y), s21_pow(x, y), ACCU);
}
END_TEST

START_TEST(pow24) {
  long double x = 0.0, y = 1.0;
  ck_assert_double_eq_tol(pow(x, y), s21_pow(x, y), ACCU);
}
END_TEST

START_TEST(pow25) {
  long double x = 0.689, y = 7.0;
  ck_assert_double_eq_tol(pow(x, y), s21_pow(x, y), ACCU);
}
END_TEST

START_TEST(pow26) {
  long double x = -2.6, y = 3.45;
  ck_assert_float_nan(s21_pow(x, y));
}
END_TEST

START_TEST(pow27) {
  long double x = 10.0, y = 1.5;
  ck_assert_double_eq_tol(pow(x, y), s21_pow(x, y), ACCU);
}
END_TEST

START_TEST(pow28) {
  long double x = 1.5, y = 1.5;
  ck_assert_double_eq_tol(pow(x, y), s21_pow(x, y), ACCU);
}
END_TEST

START_TEST(pow29) {
  long double x = 0.1, y = 0.1;
  ck_assert_double_eq_tol(pow(x, y), s21_pow(x, y), ACCU);
}
END_TEST

START_TEST(pow30) {
  long double x = 0.215, y = 0.215;
  ck_assert_double_eq_tol(pow(x, y), s21_pow(x, y), ACCU);
}
END_TEST

START_TEST(pow31) {
  long double x = 0.978464, y = 5.0;
  ck_assert_double_eq_tol(pow(x, y), s21_pow(x, y), ACCU);
}
END_TEST

START_TEST(pow32) {
  long double x = 0.986, y = 10.0;
  ck_assert_double_eq_tol(pow(x, y), s21_pow(x, y), ACCU);
}
END_TEST

START_TEST(pow33) {
  long double x = 8.654, y = 0.7;
  ck_assert_double_eq_tol(pow(x, y), s21_pow(x, y), ACCU);
}
END_TEST

START_TEST(pow34) {
  long double x = 8.654, y = -0.7;
  ck_assert_double_eq_tol(pow(x, y), s21_pow(x, y), ACCU);
}
END_TEST

START_TEST(pow35) {
  long double x = S21_NAN, y = -0.7;
  ck_assert_float_nan(s21_pow(x, y));
}
END_TEST

START_TEST(pow36) {
  long double x = S21_NAN, y = 0.7;
  ck_assert_float_nan(s21_pow(x, y));
}
END_TEST

START_TEST(pow37) {
  long double x = S21_NAN, y = S21_NAN;
  ck_assert_float_nan(s21_pow(x, y));
}
END_TEST

START_TEST(pow38) {
  long double x = 0.7, y = S21_NAN;
  ck_assert_float_nan(s21_pow(x, y));
}
END_TEST

START_TEST(pow39) {
  long double x = -0.7, y = S21_NAN;
  ck_assert_float_nan(s21_pow(x, y));
}
END_TEST

START_TEST(pow40) {
  long double x = 0.7, y = S21_NAN;
  ck_assert_float_nan(s21_pow(x, y));
}
END_TEST

START_TEST(pow41) {
  long double x = S21_INFINITY, y = S21_INFINITY;
  ck_assert_float_infinite(s21_pow(x, y));
}
END_TEST

START_TEST(pow42) {
  long double x = S21_INFINITY, y = -S21_INFINITY;
  ck_assert_double_eq_tol(pow(x, y), s21_pow(x, y), ACCU);
}
END_TEST

START_TEST(pow43) {
  long double x = -S21_INFINITY, y = S21_INFINITY;
  ck_assert_float_infinite(s21_pow(x, y));
}
END_TEST

START_TEST(pow44) {
  long double x = -S21_INFINITY, y = -S21_INFINITY;
  ck_assert_double_eq_tol(pow(x, y), s21_pow(x, y), ACCU);
}
END_TEST

START_TEST(pow45) {
  long double x = 8.654, y = -0.7;
  ck_assert_double_eq_tol(pow(x, y), s21_pow(x, y), ACCU);
}
END_TEST

START_TEST(pow46) {
  long double x = 0.978464, y = -5;
  ck_assert_double_eq_tol(pow(x, y), s21_pow(x, y), ACCU);
}
END_TEST

START_TEST(pow47) {
  long double x = 0.756, y = -7;
  ck_assert_double_eq_tol(pow(x, y), s21_pow(x, y), ACCU);
}
END_TEST

START_TEST(pow48) {
  long double x = 0, y = 5;
  ck_assert_double_eq_tol(pow(x, y), s21_pow(x, y), ACCU);
}
END_TEST

START_TEST(pow49) {
  long double x = 0, y = -5;
  ck_assert_float_infinite(s21_pow(x, y));
}
END_TEST

START_TEST(sqrt1) {
  long double x = 0.0;
  ck_assert_double_eq_tol(sqrt(x), s21_sqrt(x), ACCU);
}
END_TEST

START_TEST(sqrt2) {
  long double x = -3.0;
  ck_assert_float_nan(s21_sqrt(x));
}
END_TEST

START_TEST(sqrt3) {
  long double x = 122.0;
  ck_assert_double_eq_tol(sqrt(x), s21_sqrt(x), ACCU);
}
END_TEST

START_TEST(sqrt4) {
  long double x = -122.0;
  ck_assert_double_nan(s21_sqrt(x));
}
END_TEST

START_TEST(sqrt5) {
  long double x = S21_LDBL_MAX;
  ck_assert_float_nan(s21_sqrt(x));
}
END_TEST

START_TEST(sqrt6) {
  long double x = S21_LDBL_MIN;
  ck_assert_double_eq_tol(sqrt(x), s21_sqrt(x), ACCU);
}
END_TEST

START_TEST(sqrt7) {
  long double x = S21_NAN;
  ck_assert_float_nan(s21_sqrt(x));
}
END_TEST

START_TEST(sqrt8) {
  long double x = S21_INFINITY;
  ck_assert_float_nan(s21_sqrt(x));
}
END_TEST

START_TEST(sqrt9) {
  long double x = -S21_INFINITY;
  ck_assert_float_nan(s21_sqrt(x));
}
END_TEST

START_TEST(sqrt10) {
  long double x = 1000;
  ck_assert_double_eq_tol(sqrt(x), s21_sqrt(x), ACCU);
}
END_TEST

START_TEST(sqrt11) {
  long double x = -5;
  ck_assert_float_nan(s21_sqrt(x));
}
END_TEST

START_TEST(sqrt12) {
  for (double i = 0; i < 21; i += 3) {
    double a = s21_sqrt(i);
    double b = sqrt(i);
    ck_assert_double_eq_tol(a, b, ACCU);
  }
}
END_TEST

START_TEST(sin1) {
  for (int R = 20; R >= -20; R -= 4) {
    for (double k = 2 * S21_PI; k > -2 * S21_PI; k -= S21_PI / 17) {
      ck_assert_double_eq_tol(sin(k + R * S21_PI), s21_sin(k + R * S21_PI),
                              ACCU);
    }
  }
}
END_TEST

START_TEST(sin2) {
  for (int R = 5; R >= -15; R -= 2) {
    for (double k = 2 * S21_PI; k > -2 * S21_PI; k -= S21_PI / 15) {
      ck_assert_double_eq_tol(sin(k + R * S21_PI), s21_sin(k + R * S21_PI),
                              ACCU);
    }
  }
}
END_TEST

START_TEST(sin3) {
  ck_assert_ldouble_nan(s21_sin(S21_INFINITY));
  ck_assert_ldouble_nan(s21_sin(-S21_INFINITY));
  ck_assert_ldouble_nan(s21_sin(S21_NAN));
  ck_assert_ldouble_nan(s21_sin(S21_NAN));
  ck_assert_ldouble_eq_tol(s21_sin(0.5), sin(0.5), ACCU);
  ck_assert_ldouble_eq_tol(s21_sin(-0.5), sin(-0.5), ACCU);
  ck_assert_ldouble_eq_tol(s21_sin(-1), sin(-1), ACCU);
  ck_assert_ldouble_eq_tol(s21_sin(1), sin(1), ACCU);
  ck_assert_ldouble_eq_tol(s21_sin(1.1), sin(1.1), ACCU);
  ck_assert_ldouble_eq_tol(s21_sin(-2.1), sin(-2.1), ACCU);
  ck_assert_ldouble_eq_tol(s21_sin(0), sin(0), ACCU);
  ck_assert_ldouble_eq_tol(s21_sin(-0), sin(-0), ACCU);
  ck_assert_ldouble_eq_tol(s21_sin(5.123456789123), sin(5.123456789123), ACCU);
  ck_assert_ldouble_eq_tol(s21_sin(0.00000004564897), sin(0.00000004564897),
                           ACCU);
  ck_assert_ldouble_eq_tol(s21_sin(-S21_2_PI), sin(-S21_2_PI), ACCU);
  ck_assert_ldouble_eq_tol(s21_sin(100000000), sin(100000000), ACCU);
  ck_assert_ldouble_eq_tol(s21_sin(-100000000), sin(-100000000), ACCU);
}
END_TEST

START_TEST(cos1) {
  for (int R = 20; R >= -20; R -= 4) {
    for (double k = 2 * S21_PI; k > -2 * S21_PI; k -= S21_PI / 17) {
      ck_assert_double_eq_tol(cos(k + R * S21_PI), s21_cos(k + R * S21_PI),
                              ACCU);
    }
  }
}
END_TEST

START_TEST(cos2) {
  for (int R = 5; R >= -15; R -= 2) {
    for (double k = 2 * S21_PI; k > -2 * S21_PI; k -= S21_PI / 12) {
      ck_assert_double_eq_tol(cos(k + R * S21_PI), s21_cos(k + R * S21_PI),
                              ACCU);
    }
  }
  double x = 3 * S21_PI;
  ck_assert_double_eq_tol(cos(x), s21_cos(x), ACCU);
}
END_TEST

START_TEST(cos3) {
  ck_assert_ldouble_nan(s21_cos(S21_INFINITY));
  ck_assert_ldouble_nan(s21_cos(-S21_INFINITY));
  ck_assert_ldouble_nan(s21_cos(S21_NAN));
  ck_assert_ldouble_nan(s21_cos(S21_NAN));
  ck_assert_ldouble_eq_tol(s21_cos(0.5), cos(0.5), ACCU);
  ck_assert_ldouble_eq_tol(s21_cos(-0.5), cos(-0.5), ACCU);
  ck_assert_ldouble_eq_tol(s21_cos(-1), cos(-1), ACCU);
  ck_assert_ldouble_eq_tol(s21_cos(1), cos(1), ACCU);
  ck_assert_ldouble_eq_tol(s21_cos(1.1), cos(1.1), ACCU);
  ck_assert_ldouble_eq_tol(s21_cos(1.5), cos(1.5), ACCU);
  ck_assert_ldouble_eq_tol(s21_cos(-2.1), cos(-2.1), ACCU);
  ck_assert_ldouble_eq_tol(s21_cos(0), cos(0), ACCU);
  ck_assert_ldouble_eq_tol(s21_cos(-0), cos(-0), ACCU);
  ck_assert_ldouble_eq_tol(s21_cos(5.123456789123), cos(5.123456789123), ACCU);
  ck_assert_ldouble_eq_tol(s21_cos(0.00000004564897), cos(0.00000004564897),
                           ACCU);
  ck_assert_ldouble_eq_tol(s21_cos(S21_PI_2), cos(S21_PI_2), ACCU);
}
END_TEST

START_TEST(tan1) {
  for (int R = 20; R >= -20; R -= 4) {
    for (double k = 2 * S21_PI; k > -2 * S21_PI; k -= S21_PI / 9) {
      ck_assert_double_eq_tol(tan(k + R * S21_PI), s21_tan(k + R * S21_PI),
                              ACCU);
    }
  }
}
END_TEST

START_TEST(tan2) {
  ck_assert_ldouble_nan(s21_cos(S21_INFINITY));
  ck_assert_ldouble_nan(s21_cos(-S21_INFINITY));
  ck_assert_ldouble_nan(s21_cos(S21_NAN));
  ck_assert_ldouble_nan(s21_cos(-S21_NAN));
  ck_assert_ldouble_eq_tol(s21_tan(-0.5), tan(-0.5), ACCU);
  ck_assert_ldouble_eq_tol(s21_tan(-1), tan(-1), ACCU);
  ck_assert_ldouble_eq_tol(s21_tan(1), tan(1), ACCU);
  ck_assert_ldouble_eq_tol(s21_tan(1.1), tan(1.1), ACCU);
  ck_assert_ldouble_eq_tol(s21_tan(-2.1), tan(-2.1), ACCU);
  ck_assert_ldouble_eq_tol(s21_tan(0), tan(0), ACCU);
  ck_assert_ldouble_eq_tol(s21_tan(-0), tan(-0), ACCU);
  ck_assert_ldouble_eq_tol(s21_tan(0.00000004564897), tan(0.00000004564897),
                           ACCU);
  ck_assert_ldouble_eq_tol(s21_tan(170000000.1), tan(170000000.1), ACCU);
}
END_TEST

START_TEST(asin1) {
  for (float k = -1; k <= 1; k += 0.1) {
    double a = s21_asin(k);
    double b = asin(k);
    ck_assert_double_eq_tol(a, b, ACCU);
  }
  ck_assert_double_eq_tol(asin(1.0), s21_asin(1.0), ACCU);
  ck_assert_double_eq_tol(asin(-1.0), s21_asin(-1.0), ACCU);
}
END_TEST

START_TEST(asin2) {
  for (float k = -1; k <= 1; k += 0.0771) {
    double a = s21_asin(k);
    double b = asin(k);
    ck_assert_double_eq_tol(a, b, ACCU);
  }
}
END_TEST

START_TEST(acos1) {
  for (float k = 0; k <= 1; k += 0.1) {
    double a = s21_acos(k);
    double b = acos(k);
    ck_assert_double_eq_tol(a, b, ACCU);
  }
}
END_TEST

START_TEST(acos2) {
  for (float k = -1; k <= 0; k += 0.1) {
    double a = s21_acos(k);
    double b = acos(k);
    ck_assert_double_eq_tol(a, b, ACCU);
  }
}
END_TEST

START_TEST(acos3) {
  for (float k = -1; k <= 0; k += 0.0305) {
    double a = s21_acos(k);
    double b = acos(k);
    ck_assert_double_eq_tol(a, b, ACCU);
  }
}
END_TEST

START_TEST(acos4) {
  for (float k = 0; k <= 1; k += 0.0305) {
    double a = s21_acos(k);
    double b = acos(k);
    ck_assert_double_eq_tol(a, b, ACCU);
  }
}
END_TEST

START_TEST(acos5) {
  ck_assert_ldouble_nan(s21_acos(S21_INFINITY));
  ck_assert_ldouble_nan(s21_acos(-S21_INFINITY));
  ck_assert_ldouble_nan(s21_acos(S21_NAN));
  ck_assert_ldouble_nan(s21_acos(-S21_NAN));
  ck_assert_ldouble_eq_tol(s21_acos(0.5), acos(0.5), ACCU);
  ck_assert_ldouble_eq_tol(s21_acos(-0.5), acos(-0.5), ACCU);
  ck_assert_ldouble_eq_tol(s21_acos(-1), acos(-1), ACCU);
  ck_assert_ldouble_eq_tol(s21_acos(1), acos(1), ACCU);
  ck_assert_ldouble_nan(s21_acos(1.1));
  ck_assert_ldouble_eq_tol(s21_acos(0), acos(0), ACCU);
  ck_assert_ldouble_eq_tol(s21_acos(-0), acos(-0), ACCU);
  ck_assert_ldouble_eq_tol(s21_acos(0.7), acos(0.7), ACCU);
  ck_assert_ldouble_eq_tol(s21_acos(0.00000004564897), acos(0.00000004564897),
                           ACCU);
}
END_TEST

START_TEST(atan1) {
  for (float k = -10; k <= 10; k += 4) {
    double a = s21_atan(k);
    double b = atan(k);
    ck_assert_double_eq_tol(a, b, ACCU);
  }
  ck_assert_double_eq_tol(s21_atan(0.0), atan(0.0), ACCU);
  ck_assert_double_eq_tol(s21_atan(1.0), atan(1.0), ACCU);
  ck_assert_double_eq_tol(s21_atan(-1.0), atan(-1.0), ACCU);
  ck_assert_double_eq_tol(s21_atan(S21_INFINITY), atan(S21_INFINITY), ACCU);
  ck_assert_double_eq_tol(s21_atan(-S21_INFINITY), atan(-S21_INFINITY), ACCU);
}
END_TEST

START_TEST(atan_2) {
  double a = 12;
  ck_assert_double_eq_tol(atan(a), s21_atan(a), ACCU);
  a = 0.4;
  ck_assert_double_eq_tol(atan(a), s21_atan(a), ACCU);
  a = -0.333;
  ck_assert_double_eq_tol(atan(a), s21_atan(a), ACCU);
  a = 30;
  ck_assert_double_eq_tol(atan(a), s21_atan(a), ACCU);
  a = 13.54;
  ck_assert_double_eq_tol(atan(a), s21_atan(a), ACCU);
  a = S21_E;
  ck_assert_double_eq_tol(atan(a), s21_atan(a), ACCU);
}
END_TEST

START_TEST(sin_cos_tan_test) {
  ck_assert_double_nan(s21_sin(S21_NAN));
  ck_assert_double_nan(s21_cos(S21_NAN));
  ck_assert_double_nan(s21_tan(S21_NAN));
  ck_assert_double_nan(s21_sin(S21_INFINITY));
  ck_assert_double_nan(s21_cos(S21_INFINITY));
  ck_assert_double_nan(s21_tan(S21_INFINITY));
  ck_assert_double_nan(s21_sin(-S21_INFINITY));
  ck_assert_double_nan(s21_cos(-S21_INFINITY));
  ck_assert_double_nan(s21_tan(-S21_INFINITY));
}
END_TEST

START_TEST(asin_acos_atan_test) {
  ck_assert_double_nan(s21_asin(S21_NAN));
  ck_assert_double_nan(s21_acos(S21_NAN));
  ck_assert_double_nan(s21_atan(S21_NAN));
  ck_assert_double_nan(s21_asin(S21_INFINITY));
  ck_assert_double_nan(s21_acos(S21_INFINITY));
  ck_assert_double_nan(s21_asin(-S21_INFINITY));
  ck_assert_double_nan(s21_acos(-S21_INFINITY));
  ck_assert_double_eq(atan(-INFINITY), atan(-S21_INFINITY));
  ck_assert_double_nan(s21_asin(5));
  ck_assert_double_nan(s21_acos(6));
  ck_assert_double_nan(s21_asin(-8));
}
END_TEST

int main(void) {
  Suite *s1 = suite_create("Core");
  TCase *tc1_1 = tcase_create("Core");
  SRunner *sr = srunner_create(s1);
  int nf;

  suite_add_tcase(s1, tc1_1);
  tcase_add_test(tc1_1, floor_1);
  tcase_add_test(tc1_1, floor_2);
  tcase_add_test(tc1_1, floor_3);
  tcase_add_test(tc1_1, floor_4);
  tcase_add_test(tc1_1, floor_5);
  tcase_add_test(tc1_1, floor_6);
  tcase_add_test(tc1_1, floor_7);
  tcase_add_test(tc1_1, floor_8);
  tcase_add_test(tc1_1, floor_9);
  tcase_add_test(tc1_1, floor_10);
  tcase_add_test(tc1_1, floor_11);
  tcase_add_test(tc1_1, floor_12);
  tcase_add_test(tc1_1, floor_13);
  tcase_add_test(tc1_1, floor_14);
  tcase_add_test(tc1_1, floor_15);
  tcase_add_test(tc1_1, floor_16);
  tcase_add_test(tc1_1, floor_17);
  tcase_add_test(tc1_1, floor_18);

  tcase_add_test(tc1_1, fmod1);
  tcase_add_test(tc1_1, fmod2);
  tcase_add_test(tc1_1, fmod3);
  tcase_add_test(tc1_1, fmod4);
  tcase_add_test(tc1_1, fmod5);
  tcase_add_test(tc1_1, fmod6);
  tcase_add_test(tc1_1, fmod7);
  tcase_add_test(tc1_1, fmod8);
  tcase_add_test(tc1_1, fmod9);
  tcase_add_test(tc1_1, fmod10);

  tcase_add_test(tc1_1, ceil1);
  tcase_add_test(tc1_1, ceil2);
  tcase_add_test(tc1_1, ceil3);
  tcase_add_test(tc1_1, ceil4);
  tcase_add_test(tc1_1, ceil5);
  tcase_add_test(tc1_1, ceil6);
  tcase_add_test(tc1_1, ceil7);
  tcase_add_test(tc1_1, ceil8);
  tcase_add_test(tc1_1, ceil9);
  tcase_add_test(tc1_1, ceil10);
  tcase_add_test(tc1_1, ceil11);
  tcase_add_test(tc1_1, ceil12);
  tcase_add_test(tc1_1, ceil13);
  tcase_add_test(tc1_1, ceil14);
  tcase_add_test(tc1_1, ceil15);
  tcase_add_test(tc1_1, ceil16);

  tcase_add_test(tc1_1, abs1);
  tcase_add_test(tc1_1, abs2);
  tcase_add_test(tc1_1, abs3);
  tcase_add_test(tc1_1, abs4);
  tcase_add_test(tc1_1, abs5);
  tcase_add_test(tc1_1, abs6);
  tcase_add_test(tc1_1, abs7);

  tcase_add_test(tc1_1, fabs1);
  tcase_add_test(tc1_1, fabs2);
  tcase_add_test(tc1_1, fabs3);
  tcase_add_test(tc1_1, fabs4);
  tcase_add_test(tc1_1, fabs5);
  tcase_add_test(tc1_1, fabs6);
  tcase_add_test(tc1_1, fabs7);
  tcase_add_test(tc1_1, fabs8);
  tcase_add_test(tc1_1, fabs9);
  tcase_add_test(tc1_1, fabs10);
  tcase_add_test(tc1_1, fabs11);
  tcase_add_test(tc1_1, fabs12);
  tcase_add_test(tc1_1, fabs13);
  tcase_add_test(tc1_1, fabs14);
  tcase_add_test(tc1_1, fabs15);

  tcase_add_test(tc1_1, exp1);
  tcase_add_test(tc1_1, exp_2);
  tcase_add_test(tc1_1, exp3);
  tcase_add_test(tc1_1, exp4);
  tcase_add_test(tc1_1, exp5);
  tcase_add_test(tc1_1, exp6);
  tcase_add_test(tc1_1, exp7);
  tcase_add_test(tc1_1, exp8);
  tcase_add_test(tc1_1, exp9);
  tcase_add_test(tc1_1, exp10);
  tcase_add_test(tc1_1, exp11);
  tcase_add_test(tc1_1, exp12);
  tcase_add_test(tc1_1, exp13);
  tcase_add_test(tc1_1, exp14);
  tcase_add_test(tc1_1, exp15);

  tcase_add_test(tc1_1, log1);
  tcase_add_test(tc1_1, log_2);
  tcase_add_test(tc1_1, log3);
  tcase_add_test(tc1_1, log4);
  tcase_add_test(tc1_1, log5);
  tcase_add_test(tc1_1, log6);
  tcase_add_test(tc1_1, log7);
  tcase_add_test(tc1_1, log8);
  tcase_add_test(tc1_1, log9);
  tcase_add_test(tc1_1, log_10);
  tcase_add_test(tc1_1, log11);
  tcase_add_test(tc1_1, log12);
  tcase_add_test(tc1_1, log13);
  tcase_add_test(tc1_1, log14);
  tcase_add_test(tc1_1, log15);

  tcase_add_test(tc1_1, pow1);
  tcase_add_test(tc1_1, pow2);
  tcase_add_test(tc1_1, pow3);
  tcase_add_test(tc1_1, pow4);
  tcase_add_test(tc1_1, pow5);
  tcase_add_test(tc1_1, pow6);
  tcase_add_test(tc1_1, pow7);
  tcase_add_test(tc1_1, pow8);
  tcase_add_test(tc1_1, pow9);
  tcase_add_test(tc1_1, pow10);
  tcase_add_test(tc1_1, pow11);
  tcase_add_test(tc1_1, pow12);
  tcase_add_test(tc1_1, pow13);
  tcase_add_test(tc1_1, pow14);
  tcase_add_test(tc1_1, pow15);
  tcase_add_test(tc1_1, pow16);
  tcase_add_test(tc1_1, pow17);
  tcase_add_test(tc1_1, pow18);
  tcase_add_test(tc1_1, pow19);
  tcase_add_test(tc1_1, pow20);
  tcase_add_test(tc1_1, pow21);
  tcase_add_test(tc1_1, pow22);
  tcase_add_test(tc1_1, pow23);
  tcase_add_test(tc1_1, pow24);
  tcase_add_test(tc1_1, pow25);
  tcase_add_test(tc1_1, pow26);
  tcase_add_test(tc1_1, pow27);
  tcase_add_test(tc1_1, pow28);
  tcase_add_test(tc1_1, pow29);
  tcase_add_test(tc1_1, pow30);
  tcase_add_test(tc1_1, pow31);
  tcase_add_test(tc1_1, pow32);
  tcase_add_test(tc1_1, pow33);
  tcase_add_test(tc1_1, pow34);
  tcase_add_test(tc1_1, pow35);
  tcase_add_test(tc1_1, pow36);
  tcase_add_test(tc1_1, pow37);
  tcase_add_test(tc1_1, pow38);
  tcase_add_test(tc1_1, pow39);
  tcase_add_test(tc1_1, pow40);
  tcase_add_test(tc1_1, pow41);
  tcase_add_test(tc1_1, pow42);
  tcase_add_test(tc1_1, pow43);
  tcase_add_test(tc1_1, pow44);
  tcase_add_test(tc1_1, pow45);
  tcase_add_test(tc1_1, pow46);
  tcase_add_test(tc1_1, pow47);
  tcase_add_test(tc1_1, pow48);
  tcase_add_test(tc1_1, pow49);

  tcase_add_test(tc1_1, sqrt1);
  tcase_add_test(tc1_1, sqrt2);
  tcase_add_test(tc1_1, sqrt3);
  tcase_add_test(tc1_1, sqrt4);
  tcase_add_test(tc1_1, sqrt5);
  tcase_add_test(tc1_1, sqrt6);
  tcase_add_test(tc1_1, sqrt7);
  tcase_add_test(tc1_1, sqrt8);
  tcase_add_test(tc1_1, sqrt9);
  tcase_add_test(tc1_1, sqrt10);
  tcase_add_test(tc1_1, sqrt11);
  tcase_add_test(tc1_1, sqrt12);

  tcase_add_test(tc1_1, sin1);
  tcase_add_test(tc1_1, sin2);
  tcase_add_test(tc1_1, sin3);

  tcase_add_test(tc1_1, cos1);
  tcase_add_test(tc1_1, cos2);
  tcase_add_test(tc1_1, cos3);

  tcase_add_test(tc1_1, tan1);
  tcase_add_test(tc1_1, tan2);

  tcase_add_test(tc1_1, asin1);
  tcase_add_test(tc1_1, asin2);

  tcase_add_test(tc1_1, acos1);
  tcase_add_test(tc1_1, acos2);
  tcase_add_test(tc1_1, acos3);
  tcase_add_test(tc1_1, acos4);
  tcase_add_test(tc1_1, acos5);

  tcase_add_test(tc1_1, atan1);
  tcase_add_test(tc1_1, atan_2);

  tcase_add_test(tc1_1, sin_cos_tan_test);

  tcase_add_test(tc1_1, asin_acos_atan_test);

  srunner_run_all(sr, CK_ENV);
  nf = srunner_ntests_failed(sr);
  srunner_free(sr);

  return nf == 0 ? 0 : 1;
}