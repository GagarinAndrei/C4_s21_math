#include "tests.h"

START_TEST(cos_1) { ck_assert_ldouble_eq_tol(s21_cos(-0), cos(-0), 1e-6); }
END_TEST
START_TEST(cos_2) { ck_assert_ldouble_eq_tol(s21_cos(-1), cos(-1), 1e-6); }
END_TEST
START_TEST(cos_3) {
  ck_assert_ldouble_eq_tol(s21_cos(-3.456), cos(-3.456), 1e-6);
}
END_TEST
START_TEST(cos_4) {
  ck_assert_ldouble_eq_tol(s21_cos(0.654), cos(0.654), 1e-6);
}
END_TEST

Suite *test_cos(void) {
  Suite *suite = suite_create("***s21_cos***");
  TCase *test_case = tcase_create("s21_cos_tc");
  tcase_add_test(test_case, cos_1);
  tcase_add_test(test_case, cos_2);
  tcase_add_test(test_case, cos_3);
  tcase_add_test(test_case, cos_4);

  suite_add_tcase(suite, test_case);
  return suite;
}