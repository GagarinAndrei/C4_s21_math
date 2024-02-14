#include "tests.h"

START_TEST(floor1) { ck_assert_ldouble_eq(s21_floor(-0.0), floor(-0.0)); }
END_TEST
START_TEST(floor2) { ck_assert_ldouble_eq(s21_floor(24.654), floor(24.654)); }
END_TEST
START_TEST(floor3) { ck_assert_ldouble_eq(s21_floor(0.2), floor(0.2)); }
END_TEST
START_TEST(floor4) { ck_assert_ldouble_eq(s21_floor(-0.27), floor(-0.27)); }
END_TEST

// START_TEST(floor_1) {
//   double x = 0;
//   ck_assert_double_eq_tol(floor(x), s21_floor(x), ACCU);
// }
// END_TEST

// START_TEST(floor_2) {
//   double x = S21_INFINITY;
//   ck_assert_double_infinite(s21_floor(x));
// }
// END_TEST

// START_TEST(floor_3) {
//   double x = -S21_INFINITY;
//   ck_assert_double_infinite(s21_floor(x));
// }
// END_TEST

// START_TEST(floor_4) {
//   double x = 2.5;
//   ck_assert_double_eq_tol(floor(x), s21_floor(x), ACCU);
// }
// END_TEST

// START_TEST(floor_5) {
//   double x = -2.5;
//   ck_assert_double_eq_tol(floor(x), s21_floor(x), ACCU);
// }
// END_TEST

// START_TEST(floor_6) {
//   double x = S21_LDBL_MAX;
//   ck_assert_double_infinite(s21_floor(x));
// }
// END_TEST

// START_TEST(floor_7) {
//   double x = S21_LDBL_MIN;
//   ck_assert_double_eq_tol(floor(x), s21_floor(x), ACCU);
// }
// END_TEST

// START_TEST(floor_8) {
//   double x = NAN;
//   ck_assert_double_nan(s21_floor(x));
// }
// END_TEST

// START_TEST(floor_9) {
//   double x = -7.0;
//   ck_assert_double_eq_tol(floor(x), s21_floor(x), ACCU);
// }
// END_TEST

// START_TEST(floor_10) {
//   double x = -98.1;
//   ck_assert_double_eq_tol(floor(x), s21_floor(x), ACCU);
// }
// END_TEST

// START_TEST(floor_11) {
//   double x = 123.02;
//   ck_assert_double_eq_tol(floor(x), s21_floor(x), ACCU);
// }
// END_TEST

// START_TEST(floor_12) {
//   double x = 10009.00123;
//   ck_assert_double_eq_tol(floor(x), s21_floor(x), ACCU);
// }
// END_TEST

// START_TEST(floor_13) {
//   double x = -10009.00123;
//   ck_assert_double_eq_tol(floor(x), s21_floor(x), ACCU);
// }
// END_TEST

// START_TEST(floor_14) {
//   double x = -0.10009;
//   ck_assert_double_eq_tol(floor(x), s21_floor(x), ACCU);
// }
// END_TEST

// START_TEST(floor_15) {
//   double x = -10009.00123;
//   ck_assert_double_eq_tol(floor(x), s21_floor(x), ACCU);
// }
// END_TEST

// START_TEST(floor_16) {
//   double x = -10009.555;
//   ck_assert_double_eq_tol(floor(x), s21_floor(x), ACCU);
// }
// END_TEST

// START_TEST(floor_17) {
//   double x = -1e-23;
//   ck_assert_double_eq_tol(floor(x), s21_floor(x), ACCU);
// }
// END_TEST

// START_TEST(floor_18) {
//   double x = 100091234.5;
//   ck_assert_double_eq_tol(floor(x), s21_floor(x), ACCU);
// }
// END_TEST

Suite *test_floor(void) {
  Suite *suite = suite_create("\033[45m***s21_floor***\033[0m");
  TCase *test_case = tcase_create("s21_floor_tc");
  tcase_add_test(test_case, floor1);
  tcase_add_test(test_case, floor2);
  tcase_add_test(test_case, floor3);
  tcase_add_test(test_case, floor4);
  // tcase_add_test(test_case, floor_1);
  // tcase_add_test(test_case, floor_2);
  // tcase_add_test(test_case, floor_3);
  // tcase_add_test(test_case, floor_4);
  // tcase_add_test(test_case, floor_5);
  // tcase_add_test(test_case, floor_6);
  // tcase_add_test(test_case, floor_7);
  // tcase_add_test(test_case, floor_8);
  // tcase_add_test(test_case, floor_9);
  // tcase_add_test(test_case, floor_10);
  // tcase_add_test(test_case, floor_11);
  // tcase_add_test(test_case, floor_12);
  // tcase_add_test(test_case, floor_13);
  // tcase_add_test(test_case, floor_14);
  // tcase_add_test(test_case, floor_15);
  // tcase_add_test(test_case, floor_16);
  // tcase_add_test(test_case, floor_17);
  // tcase_add_test(test_case, floor_18);
  suite_add_tcase(suite, test_case);
  return suite;
}