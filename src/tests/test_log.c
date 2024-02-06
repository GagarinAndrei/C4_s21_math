#include <check.h>

#include "tests.h"

START_TEST(log_1) { ck_assert_ldouble_eq(s21_log(0), log(0)); }
END_TEST
START_TEST(log_2) { ck_assert_double_nan(s21_log(-1)); }
END_TEST
START_TEST(log_3) { ck_assert_double_nan(s21_log(-S21_INF)); }
END_TEST

START_TEST(log_4) { ck_assert_double_nan(s21_log(S21_NAN)); }
END_TEST

START_TEST(log_5) { ck_assert_double_eq(s21_log(S21_E), log(S21_E)); }
END_TEST

Suite *test_log(void) {
  Suite *suite = suite_create("\033[45m***s21_log***\033[0m");
  TCase *test_case = tcase_create("s21_log_tc");
  tcase_add_test(test_case, log_1);
  tcase_add_test(test_case, log_2);
  tcase_add_test(test_case, log_3);
  tcase_add_test(test_case, log_4);
  tcase_add_test(test_case, log_5);

  suite_add_tcase(suite, test_case);
  return suite;
}