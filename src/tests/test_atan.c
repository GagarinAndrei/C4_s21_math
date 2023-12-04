#include "tests.h"

START_TEST(atan_1) { ck_assert_int_eq(s21_atan(1), atan(1)); }
END_TEST
START_TEST(atan_2) { ck_assert_int_eq(s21_atan(-1), atan(-1)); }
END_TEST
START_TEST(atan_3) { ck_assert_int_eq(s21_atan(0), atan(0)); }
END_TEST
START_TEST(atan_4) { ck_assert_int_eq(s21_atan(0.654), atan(0.654)); }
END_TEST



Suite *test_atan(void) {
  Suite *suite = suite_create("***s21_atan***");
  TCase *test_case = tcase_create("s21_atan_tc");
  tcase_add_test(test_case, atan_1);
  tcase_add_test(test_case, atan_2);
  tcase_add_test(test_case, atan_3);
  tcase_add_test(test_case, atan_4);

  suite_add_tcase(suite, test_case);
  return suite;
}