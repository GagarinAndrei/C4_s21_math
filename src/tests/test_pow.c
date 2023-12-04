#include "tests.h"

START_TEST(pow_1) { ck_assert_int_eq(s21_pow(-0.0,0.0), pow(-0.0,0.0)); }
END_TEST
START_TEST(pow_2) { ck_assert_int_eq(s21_pow(-24.654,4.654), pow(-24.654,4.654)); }
END_TEST
START_TEST(pow_3) { ck_assert_int_eq(s21_pow(0.2,0.2), pow(0.2,0.2)); }
END_TEST
START_TEST(pow_4) { ck_assert_int_eq(s21_pow(0.27,-0.27), pow(0.27,-0.27)); }
END_TEST

Suite *test_pow(void) {
  Suite *suite = suite_create("***s21_pow***");
  TCase *test_case = tcase_create("s21_pow_tc");
  tcase_add_test(test_case, pow_1);
  tcase_add_test(test_case, pow_2);
  tcase_add_test(test_case, pow_3);
  tcase_add_test(test_case, pow_4);
  suite_add_tcase(suite, test_case);
  return suite;
}