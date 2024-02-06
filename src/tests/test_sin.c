#include "tests.h"

START_TEST(sin_1) { ck_assert_ldouble_eq_tol(s21_sin(0), sin(0), 1e-6); }
END_TEST
START_TEST(sin_2) { ck_assert_ldouble_eq_tol(s21_sin(-1), sin(-1), 1e-6); }
END_TEST
START_TEST(sin_3) { ck_assert_ldouble_eq_tol(s21_sin(2.2), sin(2.2), 1e-6); }
END_TEST
START_TEST(sin_4) { ck_assert_ldouble_eq_tol(s21_sin(-0.5), sin(-0.5), 1e-6); }
END_TEST
START_TEST(sin_5) { ck_assert_ldouble_eq_tol(s21_sin(0.99), sin(0.99), 1e-6); }
END_TEST

Suite *test_sin(void) {
  Suite *suite = suite_create("\033[45m***s21_sin***\033[0m");
  TCase *test_case = tcase_create("s21_sin_tc");
  tcase_add_test(test_case, sin_1);
  tcase_add_test(test_case, sin_2);
  tcase_add_test(test_case, sin_3);
  tcase_add_test(test_case, sin_4);
  tcase_add_test(test_case, sin_5);

  suite_add_tcase(suite, test_case);
  return suite;
}