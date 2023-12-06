#include "tests.h"

START_TEST(pow_1) { ck_assert_ldouble_eq_tol(s21_pow(-0.0, 0.0), pow(-0.0, 0.0), 1e-6); }
END_TEST
START_TEST(pow_2) {
  ck_assert_ldouble_eq_tol(s21_pow(2.2, 2.2), pow(2.2, 2.2), 1e-6);
}
END_TEST
START_TEST(pow_3) { ck_assert_double_nan(s21_pow(-2.2,-2.2)); }
END_TEST
START_TEST(pow_4) { ck_assert_ldouble_eq_tol(s21_pow(0, 1.1), pow(0, 1.1), 1e-6); }
END_TEST
START_TEST(pow_5) { ck_assert_double_nan(s21_pow(-9, 3.3)); }
END_TEST

Suite *test_pow(void) {
  Suite *suite = suite_create("***s21_pow***");
  TCase *test_case = tcase_create("s21_pow_tc");
  tcase_add_test(test_case, pow_1);
  tcase_add_test(test_case, pow_2);
  tcase_add_test(test_case, pow_3);
  tcase_add_test(test_case, pow_4);
  tcase_add_test(test_case, pow_5);
  suite_add_tcase(suite, test_case);
  return suite;
}