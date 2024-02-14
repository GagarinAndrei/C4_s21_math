#include "tests.h"

START_TEST(asin_1) { ck_assert_ldouble_eq(s21_asin(1), asin(1)); }
END_TEST
START_TEST(asin_2) { ck_assert_ldouble_eq(s21_asin(-1), asin(-1)); }
END_TEST

START_TEST(asin_6) { ck_assert_ldouble_eq(s21_asin(0), asin(0)); }
END_TEST
START_TEST(asin_7) { ck_assert_ldouble_eq(s21_asin(-0), asin(-0)); }
END_TEST
START_TEST(asin_8) {
  ck_assert_ldouble_eq_tol(s21_asin(0.56), asin(0.56), 1e-6);
}
END_TEST
START_TEST(asin_9) { ck_assert_double_nan(s21_asin(S21_INF)); }
END_TEST
START_TEST(asin_10) { ck_assert_double_nan(s21_asin(-S21_INF)); }
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

Suite *test_asin(void) {
  Suite *suite = suite_create("\033[45m***s21_asin***\033[0m");
  TCase *test_case = tcase_create("s21_asin_tc");
  tcase_add_test(test_case, asin_1);
  tcase_add_test(test_case, asin_2);
  tcase_add_test(test_case, asin_6);
  tcase_add_test(test_case, asin_7);
  tcase_add_test(test_case, asin_8);
  tcase_add_test(test_case, asin_9);
  tcase_add_test(test_case, asin_10);
  tcase_add_test(test_case, asin1);
  tcase_add_test(test_case, asin2);
  suite_add_tcase(suite, test_case);
  return suite;
}