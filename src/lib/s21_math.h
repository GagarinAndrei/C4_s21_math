#ifndef S21_MATH
#define S21_MATH

#define S21_PI 3.14159265358979323846
#define S21_E 2.71828182845904523536028747
#define S21_NAN (0.0 / 0.0)
#define accur 1e-10
#define S21_INF 1.0 / 0.0L
// #define S21_INF -1.0 / 0.0L
// #include <stdio.h>
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