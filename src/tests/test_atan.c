#include "tests.h"

START_TEST(atan_1) { ck_assert_ldouble_eq_tol(s21_atan(1), atan(1), 1e-6); }
END_TEST
START_TEST(atan_2) { ck_assert_ldouble_eq_tol(s21_atan(-1), atan(-1), 1e-6); }
END_TEST
START_TEST(atan_3) { ck_assert_ldouble_eq_tol(s21_atan(0), atan(0), 1e-6); }
END_TEST
START_TEST(atan_4) {
  ck_assert_ldouble_eq_tol(s21_atan(0.654), atan(0.654), 1e-6);
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
  // ck_assert_double_eq_tol(s21_atan(S21_INFINITY), atan(S21_INFINITY), ACCU);
  // ck_assert_double_eq_tol(s21_atan(-S21_INFINITY), atan(-S21_INFINITY), ACCU);
}
END_TEST

START_TEST(atan__2) {
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

Suite *test_atan(void) {
  Suite *suite = suite_create("\033[45m***s21_atan***\033[0m");
  TCase *test_case = tcase_create("s21_atan_tc");
  tcase_add_test(test_case, atan_1);
  tcase_add_test(test_case, atan_2);
  tcase_add_test(test_case, atan_3);
  tcase_add_test(test_case, atan_4);
  tcase_add_test(test_case, atan1);
  tcase_add_test(test_case, atan__2);

  suite_add_tcase(suite, test_case);
  return suite;
}