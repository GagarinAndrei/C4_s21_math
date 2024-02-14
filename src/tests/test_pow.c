#include "tests.h"

START_TEST(pow_1_1) {
  ck_assert_ldouble_eq_tol(s21_pow(-0.0, 0.0), pow(-0.0, 0.0), 1e-6);
}
END_TEST
START_TEST(pow_2_1) {
  ck_assert_ldouble_eq_tol(s21_pow(2.2, 2.2), pow(2.2, 2.2), 1e-6);
}
END_TEST
START_TEST(pow_3_1) { ck_assert_double_nan(s21_pow(-2.2, -2.2)); }
END_TEST
START_TEST(pow_4_1) {
  ck_assert_ldouble_eq_tol(s21_pow(0, 1.1), pow(0, 1.1), 1e-6);
}
END_TEST
START_TEST(pow_5_1) { ck_assert_double_nan(s21_pow(-9, 3.3)); }
END_TEST

START_TEST(pow1) {
  long double x = 0.0, y = 0.0;
  ck_assert_double_eq_tol(pow(x, y), s21_pow(x, y), ACCU);
}
END_TEST

START_TEST(pow2) {
  long double x = 0.0, y = -2.0;
  ck_assert_float_infinite(s21_pow(x, y));
}
END_TEST

START_TEST(pow3) {
  long double x = 0.0, y = 5.0;
  ck_assert_double_eq_tol(pow(x, y), s21_pow(x, y), ACCU);
}
END_TEST

START_TEST(pow4) {
  long double x = 0.0, y = 2.0;
  ck_assert_double_eq_tol(pow(x, y), s21_pow(x, y), ACCU);
}
END_TEST

START_TEST(pow5) {
  long double x = -1.0, y = S21_INFINITY;
  ck_assert_double_eq_tol(pow(x, y), s21_pow(x, y), ACCU);
}
END_TEST

START_TEST(pow6) {
  long double x = -1.0, y = -S21_INFINITY;
  ck_assert_double_eq_tol(pow(x, y), s21_pow(x, y), ACCU);
}
END_TEST

START_TEST(pow7) {
  long double x = -1.0, y = 0.5;
  ck_assert_float_nan(s21_pow(x, y));
}
END_TEST

START_TEST(pow8) {
  long double x = 0.5, y = -S21_INFINITY;
  ck_assert_float_infinite(s21_pow(x, y));
}
END_TEST

START_TEST(pow9) {
  long double x = -2, y = -S21_INFINITY;
  ck_assert_double_eq_tol(pow(x, y), s21_pow(x, y), ACCU);
}
END_TEST

START_TEST(pow10) {
  long double x = 0.5, y = S21_INFINITY;
  ck_assert_double_eq_tol(pow(x, y), s21_pow(x, y), ACCU);
}
END_TEST

START_TEST(pow11) {
  long double x = 3, y = S21_INFINITY;
  ck_assert_float_infinite(s21_pow(x, y));
}
END_TEST

START_TEST(pow12) {
  long double x = -S21_INFINITY, y = -1.0;
  ck_assert_double_eq_tol(pow(x, y), s21_pow(x, y), ACCU);
}
END_TEST

START_TEST(pow13) {
  long double x = -S21_INFINITY, y = -2.0;
  ck_assert_double_eq_tol(pow(x, y), s21_pow(x, y), ACCU);
}
END_TEST

START_TEST(pow14) {
  long double x = -S21_INFINITY, y = 3.0;
  ck_assert_float_infinite(s21_pow(x, y));
}
END_TEST

START_TEST(pow15) {
  long double x = -S21_INFINITY, y = 2.0;
  ck_assert_float_infinite(s21_pow(x, y));
}
END_TEST

START_TEST(pow16) {
  long double x = S21_INFINITY, y = -2.0;
  ck_assert_double_eq_tol(pow(x, y), s21_pow(x, y), ACCU);
}
END_TEST

START_TEST(pow17) {
  long double x = S21_INFINITY, y = 5.0;
  ck_assert_float_infinite(s21_pow(x, y));
}
END_TEST

START_TEST(pow18) {
  long double x = 10.0, y = -10.0;
  ck_assert_double_eq_tol(pow(x, y), s21_pow(x, y), ACCU);
}
END_TEST

START_TEST(pow19) {
  long double x = 100.0, y = 2.0;
  ck_assert_double_eq_tol(pow(x, y), s21_pow(x, y), ACCU);
}
END_TEST

START_TEST(pow20) {
  long double x = 0.0, y = -1.1;
  ck_assert_float_infinite(s21_pow(x, y));
}
END_TEST

START_TEST(pow21) {
  long double x = S21_LDBL_MAX, y = -1.1;
  ck_assert_double_eq_tol(pow(x, y), s21_pow(x, y), ACCU);
}
END_TEST

START_TEST(pow22) {
  long double x = S21_LDBL_MIN, y = -1.1;
  ck_assert_float_infinite(s21_pow(x, y));
}
END_TEST

START_TEST(pow23) {
  long double x = 1.0, y = 1.0;
  ck_assert_double_eq_tol(pow(x, y), s21_pow(x, y), ACCU);
}
END_TEST

START_TEST(pow24) {
  long double x = 0.0, y = 1.0;
  ck_assert_double_eq_tol(pow(x, y), s21_pow(x, y), ACCU);
}
END_TEST

START_TEST(pow25) {
  long double x = 0.689, y = 7.0;
  ck_assert_double_eq_tol(pow(x, y), s21_pow(x, y), ACCU);
}
END_TEST

START_TEST(pow26) {
  long double x = -2.6, y = 3.45;
  ck_assert_float_nan(s21_pow(x, y));
}
END_TEST

START_TEST(pow27) {
  long double x = 10.0, y = 1.5;
  ck_assert_double_eq_tol(pow(x, y), s21_pow(x, y), ACCU);
}
END_TEST

START_TEST(pow28) {
  long double x = 1.5, y = 1.5;
  ck_assert_double_eq_tol(pow(x, y), s21_pow(x, y), ACCU);
}
END_TEST

START_TEST(pow29) {
  long double x = 0.1, y = 0.1;
  ck_assert_double_eq_tol(pow(x, y), s21_pow(x, y), ACCU);
}
END_TEST

START_TEST(pow30) {
  long double x = 0.215, y = 0.215;
  ck_assert_double_eq_tol(pow(x, y), s21_pow(x, y), ACCU);
}
END_TEST

START_TEST(pow31) {
  long double x = 0.978464, y = 5.0;
  ck_assert_double_eq_tol(pow(x, y), s21_pow(x, y), ACCU);
}
END_TEST

START_TEST(pow32) {
  long double x = 0.986, y = 10.0;
  ck_assert_double_eq_tol(pow(x, y), s21_pow(x, y), ACCU);
}
END_TEST

START_TEST(pow33) {
  long double x = 8.654, y = 0.7;
  ck_assert_double_eq_tol(pow(x, y), s21_pow(x, y), ACCU);
}
END_TEST

START_TEST(pow34) {
  long double x = 8.654, y = -0.7;
  ck_assert_double_eq_tol(pow(x, y), s21_pow(x, y), ACCU);
}
END_TEST

START_TEST(pow35) {
  long double x = S21_NAN, y = -0.7;
  ck_assert_float_nan(s21_pow(x, y));
}
END_TEST

START_TEST(pow36) {
  long double x = S21_NAN, y = 0.7;
  ck_assert_float_nan(s21_pow(x, y));
}
END_TEST

START_TEST(pow37) {
  long double x = S21_NAN, y = S21_NAN;
  ck_assert_float_nan(s21_pow(x, y));
}
END_TEST

START_TEST(pow38) {
  long double x = 0.7, y = S21_NAN;
  ck_assert_float_nan(s21_pow(x, y));
}
END_TEST

START_TEST(pow39) {
  long double x = -0.7, y = S21_NAN;
  ck_assert_float_nan(s21_pow(x, y));
}
END_TEST

START_TEST(pow40) {
  long double x = 0.7, y = S21_NAN;
  ck_assert_float_nan(s21_pow(x, y));
}
END_TEST

START_TEST(pow41) {
  long double x = S21_INFINITY, y = S21_INFINITY;
  ck_assert_float_infinite(s21_pow(x, y));
}
END_TEST

START_TEST(pow42) {
  long double x = S21_INFINITY, y = -S21_INFINITY;
  ck_assert_double_eq_tol(pow(x, y), s21_pow(x, y), ACCU);
}
END_TEST

START_TEST(pow43) {
  long double x = -S21_INFINITY, y = S21_INFINITY;
  ck_assert_float_infinite(s21_pow(x, y));
}
END_TEST

START_TEST(pow44) {
  long double x = -S21_INFINITY, y = -S21_INFINITY;
  ck_assert_double_eq_tol(pow(x, y), s21_pow(x, y), ACCU);
}
END_TEST

START_TEST(pow45) {
  long double x = 8.654, y = -0.7;
  ck_assert_double_eq_tol(pow(x, y), s21_pow(x, y), ACCU);
}
END_TEST

START_TEST(pow46) {
  long double x = 0.978464, y = -5;
  ck_assert_double_eq_tol(pow(x, y), s21_pow(x, y), ACCU);
}
END_TEST

START_TEST(pow47) {
  long double x = 0.756, y = -7;
  ck_assert_double_eq_tol(pow(x, y), s21_pow(x, y), ACCU);
}
END_TEST

START_TEST(pow48) {
  long double x = 0, y = 5;
  ck_assert_double_eq_tol(pow(x, y), s21_pow(x, y), ACCU);
}
END_TEST

START_TEST(pow49) {
  long double x = 0, y = -5;
  ck_assert_float_infinite(s21_pow(x, y));
}
END_TEST

Suite *test_pow(void) {
  Suite *suite = suite_create("\033[45m***s21_pow***\033[0m");
  TCase *test_case = tcase_create("s21_pow_tc");
  tcase_add_test(test_case, pow_1_1);
  tcase_add_test(test_case, pow_2_1);
  tcase_add_test(test_case, pow_3_1);
  tcase_add_test(test_case, pow_4_1);
  tcase_add_test(test_case, pow_5_1);
  tcase_add_test(test_case, pow1);
  tcase_add_test(test_case, pow2);
  tcase_add_test(test_case, pow3);
  tcase_add_test(test_case, pow4);
  tcase_add_test(test_case, pow5);
  tcase_add_test(test_case, pow6);
  tcase_add_test(test_case, pow7);
  tcase_add_test(test_case, pow8);
  tcase_add_test(test_case, pow9);
  tcase_add_test(test_case, pow10);
  tcase_add_test(test_case, pow11);
  tcase_add_test(test_case, pow12);
  tcase_add_test(test_case, pow13);
  tcase_add_test(test_case, pow14);
  tcase_add_test(test_case, pow15);
  tcase_add_test(test_case, pow16);
  tcase_add_test(test_case, pow17);
  tcase_add_test(test_case, pow18);
  tcase_add_test(test_case, pow19);
  tcase_add_test(test_case, pow20);
  tcase_add_test(test_case, pow21);
  tcase_add_test(test_case, pow22);
  tcase_add_test(test_case, pow23);
  tcase_add_test(test_case, pow24);
  tcase_add_test(test_case, pow25);
  tcase_add_test(test_case, pow26);
  tcase_add_test(test_case, pow27);
  tcase_add_test(test_case, pow28);
  tcase_add_test(test_case, pow29);
  tcase_add_test(test_case, pow30);
  tcase_add_test(test_case, pow31);
  tcase_add_test(test_case, pow32);
  tcase_add_test(test_case, pow33);
  tcase_add_test(test_case, pow34);
  tcase_add_test(test_case, pow35);
  tcase_add_test(test_case, pow36);
  tcase_add_test(test_case, pow37);
  tcase_add_test(test_case, pow38);
  tcase_add_test(test_case, pow39);
  tcase_add_test(test_case, pow40);
  tcase_add_test(test_case, pow41);
  tcase_add_test(test_case, pow42);
  tcase_add_test(test_case, pow43);
  tcase_add_test(test_case, pow44);
  tcase_add_test(test_case, pow45);
  tcase_add_test(test_case, pow46);
  tcase_add_test(test_case, pow47);
  tcase_add_test(test_case, pow48);
  tcase_add_test(test_case, pow49);

  suite_add_tcase(suite, test_case);
  return suite;
}