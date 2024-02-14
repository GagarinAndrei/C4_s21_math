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

// START_TEST(fmod1) {
//   double x = 0.0, y = 0.0;
//   ck_assert_double_nan(s21_fmod(x, y));
// }
// END_TEST

// START_TEST(fmod2) {
//   double x = 1.0, y = S21_NAN;
//   ck_assert_double_nan(s21_fmod(x, y));
// }
// END_TEST

// START_TEST(fmod3) {
//   double x = S21_NAN, y = 1.0;
//   ck_assert_double_nan(s21_fmod(x, y));
// }
// END_TEST

// START_TEST(fmod4) {
//   double x = S21_INFINITY, y = 1.0;
//   ck_assert_double_nan(s21_fmod(x, y));
// }
// END_TEST

// START_TEST(fmod5) {
//   double x = 1.0, y = S21_INFINITY;
//   ck_assert_double_eq_tol(fmod(x, y), s21_fmod(x, y), ACCU);
// }
// END_TEST

// START_TEST(fmod6) {
//   double x = 0.0, y = S21_INFINITY;
//   ck_assert_double_eq_tol(fmod(x, y), s21_fmod(x, y), ACCU);
// }
// END_TEST

// START_TEST(fmod7) {
//   double x = S21_INFINITY, y = S21_INFINITY;
//   ck_assert_double_nan(s21_fmod(x, y));
// }
// END_TEST

// START_TEST(fmod8) {
//   double x = 1.0, y = 0.5;
//   ck_assert_double_eq_tol(fmod(x, y), s21_fmod(x, y), ACCU);
// }
// END_TEST

// START_TEST(fmod9) {
//   double x = 199999.00005, y = 5.0;
//   ck_assert_double_eq_tol(fmod(x, y), s21_fmod(x, y), ACCU);
// }
// END_TEST

// START_TEST(fmod10) {
//   double x = 199999.00005, y = S21_INFINITY;
//   ck_assert_double_eq_tol(fmod(x, y), s21_fmod(x, y), ACCU);
// }
// END_TEST

Suite *test_fmod(void) {
  Suite *suite = suite_create("\033[45m***s21_fmod***\033[0m");
  TCase *test_case = tcase_create("s21_fmod_tc");
  tcase_add_test(test_case, fmod_1);
  tcase_add_test(test_case, fmod_2);
  tcase_add_test(test_case, fmod_3);
  tcase_add_test(test_case, fmod_4);
  // tcase_add_test(test_case, fmod1);
  // tcase_add_test(test_case, fmod2);
  // tcase_add_test(test_case, fmod3);
  // tcase_add_test(test_case, fmod4);
  // tcase_add_test(test_case, fmod5);
  // tcase_add_test(test_case, fmod6);
  // tcase_add_test(test_case, fmod7);
  // tcase_add_test(test_case, fmod8);
  // tcase_add_test(test_case, fmod9);
  // tcase_add_test(test_case, fmod10);
  suite_add_tcase(suite, test_case);
  return suite;
}