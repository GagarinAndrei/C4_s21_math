#include "tests.h"

START_TEST(floor_1) { ck_assert_ldouble_eq(s21_floor(-0.0), floor(-0.0)); }
END_TEST
START_TEST(floor_2) { ck_assert_ldouble_eq(s21_floor(24.654), floor(24.654)); }
END_TEST
START_TEST(floor_3) { ck_assert_ldouble_eq(s21_floor(0.2), floor(0.2)); }
END_TEST
START_TEST(floor_4) { ck_assert_ldouble_eq(s21_floor(-0.27), floor(-0.27)); }
END_TEST

Suite *test_floor(void) {
  Suite *suite = suite_create("***s21_floor***");
  TCase *test_case = tcase_create("s21_floor_tc");
  tcase_add_test(test_case, floor_1);
  tcase_add_test(test_case, floor_2);
  tcase_add_test(test_case, floor_3);
  tcase_add_test(test_case, floor_4);
  suite_add_tcase(suite, test_case);
  return suite;
}