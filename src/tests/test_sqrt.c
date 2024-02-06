#include "tests.h"

START_TEST(sqrt_1) { ck_assert_ldouble_eq(s21_sqrt(0), sqrt(0)); }
END_TEST
START_TEST(sqrt_2) { ck_assert_double_nan(s21_sqrt(-1)); }
END_TEST
START_TEST(sqrt_3) { ck_assert_ldouble_eq_tol(s21_sqrt(2.2), sqrt(2.2), 1e-6); }
END_TEST
START_TEST(sqrt_4) { ck_assert_double_nan(s21_sqrt(-0.5)); }
END_TEST
START_TEST(sqrt_5) {
  ck_assert_ldouble_eq_tol(s21_sqrt(1.99), sqrt(1.99), 1e-6);
}
END_TEST

Suite *test_sqrt(void) {
  Suite *suite = suite_create("\033[45m***s21_sqrt***\033[0m");
  TCase *test_case = tcase_create("s21_sqrt_tc");
  tcase_add_test(test_case, sqrt_1);
  tcase_add_test(test_case, sqrt_2);
  tcase_add_test(test_case, sqrt_3);
  tcase_add_test(test_case, sqrt_4);
  tcase_add_test(test_case, sqrt_5);

  suite_add_tcase(suite, test_case);
  return suite;
}