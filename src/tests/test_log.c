#include <check.h>

#include "tests.h"

// START_TEST(log_1) { ck_assert_ldouble_eq(s21_log(0), log(0)); }
// END_TEST
// START_TEST(log_2) { ck_assert_double_nan(s21_log(-1)); }
// END_TEST
// START_TEST(log_3) { ck_assert_double_nan(s21_log(-S21_INF)); }
// END_TEST

// START_TEST(log_4) { ck_assert_double_nan(s21_log(S21_NAN)); }
// END_TEST

// START_TEST(log_5) { ck_assert_double_eq(s21_log(S21_E), log(S21_E)); }
// END_TEST

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

Suite *test_log(void) {
  Suite *suite = suite_create("\033[45m***s21_log***\033[0m");
  TCase *test_case = tcase_create("s21_log_tc");
  tcase_add_test(test_case, log1);
  tcase_add_test(test_case, log_2);
  tcase_add_test(test_case, log3);
  tcase_add_test(test_case, log4);
  tcase_add_test(test_case, log5);
  tcase_add_test(test_case, log6);
  tcase_add_test(test_case, log7);
  tcase_add_test(test_case, log8);
  tcase_add_test(test_case, log9);
  tcase_add_test(test_case, log_10);
  tcase_add_test(test_case, log11);
  tcase_add_test(test_case, log12);
  tcase_add_test(test_case, log13);
  tcase_add_test(test_case, log14);
  tcase_add_test(test_case, log15);

  suite_add_tcase(suite, test_case);
  return suite;
}