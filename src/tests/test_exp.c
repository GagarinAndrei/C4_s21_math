#include "tests.h"

START_TEST(exp_1) { ck_assert_ldouble_eq_tol(s21_exp(0.0), exp(0.0), 1e-6); }
END_TEST
START_TEST(exp_2) {
  ck_assert_ldouble_eq_tol(s21_exp(-24.654), exp(-24.654), 1e-6);
}
END_TEST
START_TEST(exp_3) { ck_assert_ldouble_eq_tol(s21_exp(0.22), exp(0.22), 1e-6); }
END_TEST
START_TEST(exp_4) { ck_assert_ldouble_eq_tol(s21_exp(1.27), exp(1.27), 1e-6); }
END_TEST

Suite *test_exp(void) {
  Suite *suite = suite_create("\033[45m***s21_exp***\033[0m");
  TCase *test_case = tcase_create("s21_exp_tc");
  tcase_add_test(test_case, exp_1);
  tcase_add_test(test_case, exp_2);
  tcase_add_test(test_case, exp_3);
  tcase_add_test(test_case, exp_4);
  suite_add_tcase(suite, test_case);
  return suite;
}