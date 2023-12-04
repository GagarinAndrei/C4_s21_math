#include "tests.h"

START_TEST(exp_1) { ck_assert_int_eq(s21_exp(0.0), exp(0.0)); }
END_TEST
START_TEST(exp_2) { ck_assert_int_eq(s21_exp(-24.654), exp(-24.654)); }
END_TEST
START_TEST(exp_3) { ck_assert_int_eq(s21_exp(0.22), exp(0.22)); }
END_TEST
START_TEST(exp_4) { ck_assert_int_eq(s21_exp(1.27), exp(1.27)); }
END_TEST

Suite *test_exp(void) {
  Suite *suite = suite_create("***s21_exp***");
  TCase *test_case = tcase_create("s21_exp_tc");
  tcase_add_test(test_case, exp_1);
  tcase_add_test(test_case, exp_2);
  tcase_add_test(test_case, exp_3);
  tcase_add_test(test_case, exp_4);
  suite_add_tcase(suite, test_case);
  return suite;
}