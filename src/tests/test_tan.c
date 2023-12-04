#include "tests.h"

START_TEST(tan_1) { ck_assert_int_eq(s21_tan(0), tan(0)); }
END_TEST
START_TEST(tan_2) { ck_assert_int_eq(s21_tan(-1), tan(-1)); }
END_TEST
START_TEST(tan_3) { ck_assert_int_eq(s21_tan(2.2), tan(2.2)); }
END_TEST
START_TEST(tan_4) { ck_assert_int_eq(s21_tan(-0.5), tan(-0.5)); }
END_TEST
START_TEST(tan_5) { ck_assert_int_eq(s21_tan(0.99), tan(0.99)); }
END_TEST



Suite *test_tan(void) {
  Suite *suite = suite_create("***s21_tan***");
  TCase *test_case = tcase_create("s21_tan_tc");
  tcase_add_test(test_case, tan_1);
  tcase_add_test(test_case, tan_2);
  tcase_add_test(test_case, tan_3);
  tcase_add_test(test_case, tan_4);
  tcase_add_test(test_case, tan_5);

  suite_add_tcase(suite, test_case);
  return suite;
}