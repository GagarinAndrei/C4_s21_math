#include "tests.h"

START_TEST(asin_1) { ck_assert_int_eq(s21_asin(1), asin(1)); }
END_TEST
START_TEST(asin_2) { ck_assert_int_eq(s21_asin(-1), asin(-1)); }
END_TEST
START_TEST(asin_3) { ck_assert_int_eq(s21_asin(S21_INF), asin(S21_INF)); }
END_TEST
START_TEST(asin_4) { ck_assert_int_eq(s21_asin(-S21_INF), asin(-S21_INF)); }
END_TEST
START_TEST(asin_5) { ck_assert_int_eq(s21_asin(S21_NAN), asin(S21_NAN)); }
END_TEST
START_TEST(asin_6) { ck_assert_int_eq(s21_asin(0), asin(0)); }
END_TEST
START_TEST(asin_7) { ck_assert_int_eq(s21_asin(-0), asin(-0)); }
END_TEST
START_TEST(asin_8) { ck_assert_int_eq(s21_asin(0.564654), asin(0.564654)); }
END_TEST


Suite *test_asin(void) {
  Suite *suite = suite_create("***s21_asin***");
  TCase *test_case = tcase_create("s21_asin_tc");
  tcase_add_test(test_case, asin_1);
  tcase_add_test(test_case, asin_2);
  tcase_add_test(test_case, asin_3);
  tcase_add_test(test_case, asin_4);
  tcase_add_test(test_case, asin_5);
  tcase_add_test(test_case, asin_6);
  tcase_add_test(test_case, asin_7);
  tcase_add_test(test_case, asin_8);
  suite_add_tcase(suite, test_case);
  return suite;
}