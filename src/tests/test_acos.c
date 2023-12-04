#include "tests.h"

START_TEST(acos_1) { ck_assert_int_eq(s21_acos(-0.0), acos(-0.0)); }
END_TEST
START_TEST(acos_2) { ck_assert_int_eq(s21_acos(-24.654), acos(-24.654)); }
END_TEST
START_TEST(acos_3) { ck_assert_int_eq(s21_acos(0.2), acos(0.2)); }
END_TEST
START_TEST(acos_4) { ck_assert_int_eq(s21_acos(-0.27), acos(-0.27)); }
END_TEST

Suite *test_acos(void) {
  Suite *suite = suite_create("***s21_acos***");
  TCase *test_case = tcase_create("s21_acos_tc");
  tcase_add_test(test_case, acos_1);
  tcase_add_test(test_case, acos_2);
  tcase_add_test(test_case, acos_3);
  tcase_add_test(test_case, acos_4);
  suite_add_tcase(suite, test_case);
  return suite;
}