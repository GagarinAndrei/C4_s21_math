#include "tests.h"

START_TEST(fabs_1) { ck_assert_ldouble_eq(s21_fabs(-0.0), fabs(-0.0)); }
END_TEST
START_TEST(fabs_2) { ck_assert_ldouble_eq(s21_fabs(-24.654), fabs(-24.654)); }
END_TEST
START_TEST(fabs_3) { ck_assert_ldouble_eq(s21_fabs(0.2), fabs(0.2)); }
END_TEST
START_TEST(fabs_4) { ck_assert_ldouble_eq(s21_fabs(-0.27), fabs(-0.27)); }
END_TEST

Suite *test_fabs(void) {
  Suite *suite = suite_create("***s21_fabs***");
  TCase *test_case = tcase_create("s21_fabs_tc");
  tcase_add_test(test_case, fabs_1);
  tcase_add_test(test_case, fabs_2);
  tcase_add_test(test_case, fabs_3);
  tcase_add_test(test_case, fabs_4);
  suite_add_tcase(suite, test_case);
  return suite;
}