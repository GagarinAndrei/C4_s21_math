#include "tests.h"

// START_TEST(exp_1) { ck_assert_ldouble_eq_tol(s21_exp(0.0), exp(0.0), 1e-6); }
// END_TEST
// START_TEST(exp_2) {
//   ck_assert_ldouble_eq_tol(s21_exp(-24.654), exp(-24.654), 1e-6);
// }
// END_TEST
// START_TEST(exp_3) { ck_assert_ldouble_eq_tol(s21_exp(0.22), exp(0.22), 1e-6);
// } END_TEST START_TEST(exp_4) { ck_assert_ldouble_eq_tol(s21_exp(1.27),
// exp(1.27), 1e-6); } END_TEST

START_TEST(exp_1) {
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

Suite *test_exp(void) {
  Suite *suite = suite_create("\033[45m***s21_exp***\033[0m");
  TCase *test_case = tcase_create("s21_exp_tc");
  tcase_add_test(test_case, exp_1);
  tcase_add_test(test_case, exp_2);
  tcase_add_test(test_case, exp3);
  tcase_add_test(test_case, exp4);
  tcase_add_test(test_case, exp5);
  tcase_add_test(test_case, exp6);
  tcase_add_test(test_case, exp7);
  tcase_add_test(test_case, exp8);
  tcase_add_test(test_case, exp9);
  tcase_add_test(test_case, exp10);
  tcase_add_test(test_case, exp11);
  tcase_add_test(test_case, exp12);
  tcase_add_test(test_case, exp13);
  tcase_add_test(test_case, exp14);
  tcase_add_test(test_case, exp15);
  suite_add_tcase(suite, test_case);
  return suite;
}