#include "tests.h"

START_TEST(abs_1) { ck_assert_int_eq(s21_abs(-0), abs(-0)); }
END_TEST
START_TEST(abs_2) { ck_assert_int_eq(s21_abs(-24), abs(-24)); }
END_TEST
START_TEST(abs_3) { ck_assert_int_eq(s21_abs(0), abs(0)); }
END_TEST
START_TEST(abs_4) { ck_assert_int_eq(s21_abs(27), abs(27)); }
END_TEST

Suite *test_abs(void) {
  Suite *suite = suite_create("***s21_abs***");
  TCase *test_case = tcase_create("s21_abs_tc");
  tcase_add_test(test_case, abs_1);
  tcase_add_test(test_case, abs_2);
  tcase_add_test(test_case, abs_3);
  tcase_add_test(test_case, abs_4);
  suite_add_tcase(suite, test_case);
  return suite;
}