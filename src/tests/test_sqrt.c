#include "tests.h"
#include <check.h>

START_TEST(sqrt_1) { ck_assert_ldouble_eq(s21_sqrt(0), sqrt(0)); }
END_TEST
START_TEST(sqrt_2) { ck_assert_double_nan(s21_sqrt(-1)); }
END_TEST
START_TEST(sqrt_3) { ck_assert_ldouble_eq_tol(s21_sqrt(2.2), sqrt(2.2), 1e-6); }
END_TEST
START_TEST(sqrt_4) { ck_assert_double_nan(s21_sqrt(-0.5)); }
END_TEST
START_TEST(sqrt_5) {
  ck_assert_ldouble_eq_tol(s21_sqrt(1.99), sqrt(1.99), 1e-6);
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
  ck_assert_float_infinite(s21_sqrt(x));
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
  ck_assert_float_infinite(s21_sqrt(x));
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

Suite *test_sqrt(void) {
  Suite *suite = suite_create("\033[45m***s21_sqrt***\033[0m");
  TCase *test_case = tcase_create("s21_sqrt_tc");
  tcase_add_test(test_case, sqrt_1);
  tcase_add_test(test_case, sqrt_2);
  tcase_add_test(test_case, sqrt_3);
  tcase_add_test(test_case, sqrt_4);
  tcase_add_test(test_case, sqrt_5);
  tcase_add_test(test_case, sqrt1);
  tcase_add_test(test_case, sqrt2);
  tcase_add_test(test_case, sqrt3);
  tcase_add_test(test_case, sqrt4);
  tcase_add_test(test_case, sqrt5);
  tcase_add_test(test_case, sqrt6);
  tcase_add_test(test_case, sqrt7);
  tcase_add_test(test_case, sqrt8);
  tcase_add_test(test_case, sqrt9);
  tcase_add_test(test_case, sqrt10);
  tcase_add_test(test_case, sqrt11);
  tcase_add_test(test_case, sqrt12);

  suite_add_tcase(suite, test_case);
  return suite;
}