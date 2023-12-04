#include "tests.h"

START_TEST(ceil_1) { ck_assert_int_eq(s21_ceil(-0), ceil(-0)); }
END_TEST
START_TEST(ceil_2) { ck_assert_int_eq(s21_ceil(-1), ceil(-1)); }
END_TEST
START_TEST(ceil_3) { ck_assert_int_eq(s21_ceil(-3.456), ceil(-3.456)); }
END_TEST
START_TEST(ceil_4) { ck_assert_int_eq(s21_ceil(-0.654), ceil(-0.654)); }
END_TEST



Suite *test_ceil(void) {
  Suite *suite = suite_create("***s21_ceil***");
  TCase *test_case = tcase_create("s21_ceil_tc");
  tcase_add_test(test_case, ceil_1);
  tcase_add_test(test_case, ceil_2);
  tcase_add_test(test_case, ceil_3);
  tcase_add_test(test_case, ceil_4);

  suite_add_tcase(suite, test_case);
  return suite;
}