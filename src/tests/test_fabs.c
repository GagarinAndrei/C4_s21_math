#include "tests.h"

START_TEST(fabs_1) { ck_assert_ldouble_eq(s21_fabs(-0.0), fabs(-0.0)); }
END_TEST
START_TEST(fabs_2) { ck_assert_ldouble_eq(s21_fabs(-24.654), fabs(-24.654)); }
END_TEST
START_TEST(fabs_3) { ck_assert_ldouble_eq(s21_fabs(0.2), fabs(0.2)); }
END_TEST
START_TEST(fabs_4) { ck_assert_ldouble_eq(s21_fabs(-0.27), fabs(-0.27)); }
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

Suite *test_fabs(void) {
  Suite *suite = suite_create("\033[45m***s21_fabs***\033[0m");
  TCase *test_case = tcase_create("s21_fabs_tc");
  tcase_add_test(test_case, fabs_1);
  tcase_add_test(test_case, fabs_2);
  tcase_add_test(test_case, fabs_3);
  tcase_add_test(test_case, fabs_4);
  tcase_add_test(test_case, fabs1);
  tcase_add_test(test_case, fabs2);
  tcase_add_test(test_case, fabs3);
  tcase_add_test(test_case, fabs4);
  tcase_add_test(test_case, fabs5);
  tcase_add_test(test_case, fabs6);
  tcase_add_test(test_case, fabs7);
  tcase_add_test(test_case, fabs8);
  tcase_add_test(test_case, fabs9);
  tcase_add_test(test_case, fabs10);
  tcase_add_test(test_case, fabs11);
  tcase_add_test(test_case, fabs12);
  tcase_add_test(test_case, fabs13);
  tcase_add_test(test_case, fabs14);
  tcase_add_test(test_case, fabs15);
  suite_add_tcase(suite, test_case);
  return suite;
}