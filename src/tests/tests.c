#include "tests.h"

#include <check.h>

int main(void) {
  int failed = 0;
  Suite *s21_math[] = {test_abs(),   test_acos(), test_asin(), test_atan(),
                       test_ceil(),  test_cos(),  test_exp(),  test_fabs(),
                       test_floor(), test_fmod(), test_log(),  test_pow(),
                       test_sin(),   test_sqrt(), test_tan(),  NULL};
  for (int i = 0; s21_math[i] != NULL; i++) {
    SRunner *sr = srunner_create(s21_math[i]);

    srunner_set_fork_status(sr, CK_NOFORK);
    srunner_run_all(sr, CK_NORMAL);
    failed += srunner_ntests_failed(sr);
    srunner_free(sr);
  }

  if (failed > 0)
    printf("\033[41m============ TESTS FAILED: %d ===========\033[0m\n",
           failed);
  else
    printf("\033[42m============ TESTS FAILED: %d ===========\033[0m\n",
           failed);
  return 0;
}