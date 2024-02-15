#ifndef S21_MATH
#define S21_MATH

#define S21_PI 3.14159265358979323846
#define S21_E 2.71828182845904523536028747
// #define S21_NAN (0.0 / 0.0)
// #define ACCUR 1e-10
// #define S21_INF 1.0 / 0.0L
#define EPSILON 1e-37
#define PRECISION 1000
#define ACCUR 1e-06

#define INT_MIN -2147483648
#define INT_MAX +2147483647
#define S21_LDBL_MAX 1.18973e+4932L
#define S21_LDBL_MIN 3.3621e-4932L

#define S21_NAN (0.0 / 0.0)
#define S21_INF (1.0 / 0.0)

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

#include <stdlib.h>

int s21_abs(int x);
int s21_factorial(int n);
long double s21_tan(double x);
long double s21_exp(double x);
long double s21_sin(double x);
long double s21_log(double x);
long double s21_cos(double x);
long double s21_acos(double x);
long double s21_ceil(double x);
long double s21_fabs(double x);
long double s21_sqrt(double x);
long double s21_atan(double x);
long double s21_asin(double x);
long double s21_floor(double x);
long double s21_fmod(double x, double y);
long double s21_pow(double base, double exp);
#endif