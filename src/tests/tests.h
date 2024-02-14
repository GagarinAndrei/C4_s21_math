#ifndef TESTS_H
#define TESTS_H
#include <check.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

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

#include "../s21_math.h"

Suite *test_abs(void);
Suite *test_acos(void);
Suite *test_asin(void);
Suite *test_atan(void);
Suite *test_ceil(void);
Suite *test_cos(void);
Suite *test_exp(void);
Suite *test_fabs(void);
Suite *test_floor(void);
Suite *test_fmod(void);
Suite *test_log(void);
Suite *test_pow(void);
Suite *test_sin(void);
Suite *test_sqrt(void);
Suite *test_tan(void);
#endif