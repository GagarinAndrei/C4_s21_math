#include "tests.h"

START_TEST(fmod_1) { ck_assert_double_nan(s21_fmod(-0.0, -0.0)); }
END_TEST
START_TEST(fmod_2) {
  ck_assert_ldouble_eq(s21_fmod(-24.654, -24.654), fmod(-24.654, -24.654));
}
END_TEST
START_TEST(fmod_3) { ck_assert_ldouble_eq(s21_fmod(0.2, 0.2), fmod(0.2, 0.2)); }
END_TEST
START_TEST(fmod_4) {
  ck_assert_ldouble_eq(s21_fmod(-1.27, -0.27), fmod(-1.27, -0.27));
}
END_TEST

Suite *test_fmod(void) {
  Suite *suite = suite_create("\033[45m***s21_fmod***\033[0m");
  TCase *test_case = tcase_create("s21_fmod_tc");
  tcase_add_test(test_case, fmod_1);
  tcase_add_test(test_case, fmod_2);
  tcase_add_test(test_case, fmod_3);
  tcase_add_test(test_case, fmod_4);
  suite_add_tcase(suite, test_case);
  return suite;
}