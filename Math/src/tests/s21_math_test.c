#include "../s21_math.h"

#include <check.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

START_TEST(abs_1) { ck_assert_int_eq(s21_abs(-5), abs(-5)); }
END_TEST

START_TEST(abs_2) { ck_assert_int_eq(s21_abs(0), abs(0)); }
END_TEST

START_TEST(abs_3) { ck_assert_int_eq(s21_abs(-0), abs(-0)); }
END_TEST

START_TEST(abs_4) { ck_assert_int_eq(s21_abs(-05), abs(-05)); }
END_TEST

START_TEST(abs_5) {
  ck_assert_int_eq(s21_abs(-00001234560), abs(-00001234560));
}
END_TEST

START_TEST(acos_1) { ck_assert_double_eq_tol(s21_acos(0), acos(0), S21_EPS); }
END_TEST

START_TEST(acos_2) {
  ck_assert_double_eq_tol(s21_acos(-0.369), acos(-0.369), S21_EPS);
}
END_TEST

START_TEST(acos_3) { ck_assert_double_eq_tol(s21_acos(-1), acos(-1), S21_EPS); }
END_TEST

START_TEST(acos_4) { ck_assert_double_eq_tol(s21_acos(1), acos(1), S21_EPS); }
END_TEST

START_TEST(acos_5) {
  ck_assert_double_nan(s21_acos(S21_INF_POS));
  ck_assert_double_nan(acos(S21_INF_POS));
}
END_TEST

START_TEST(acos_6) {
  ck_assert_double_nan(s21_acos(S21_NAN));
  ck_assert_double_nan(acos(S21_NAN));
}
END_TEST

START_TEST(acos_7) {
  ck_assert_double_nan(s21_acos(S21_INF_NEG));
  ck_assert_double_nan(acos(S21_INF_NEG));
}
END_TEST

START_TEST(acos_8) {
  ck_assert_double_nan(s21_acos(16));
  ck_assert_double_nan(acos(16));
}
END_TEST

START_TEST(acos_9) {
  ck_assert_double_nan(s21_acos(-16));
  ck_assert_double_nan(acos(-16));
}
END_TEST

START_TEST(asin_1) {
  ck_assert_ldouble_eq_tol(asin(0.4), s21_asin(0.4), S21_EPS);
}
END_TEST

START_TEST(asin_2) {
  ck_assert_ldouble_eq_tol(asin(-0.4), s21_asin(-0.4), S21_EPS);
}
END_TEST

START_TEST(asin_3) {
  ck_assert_ldouble_eq_tol(asin(0.0), s21_asin(0.0), S21_EPS);
}
END_TEST

START_TEST(asin_4) {
  ck_assert_ldouble_eq_tol(asin(-0.0), s21_asin(-0.0), S21_EPS);
}
END_TEST

START_TEST(asin_5) {
  ck_assert_ldouble_eq_tol(asin(-1), s21_asin(-1), S21_EPS);
}
END_TEST

START_TEST(asin_6) { ck_assert_ldouble_nan(s21_asin(5)); }
END_TEST

START_TEST(asin_7) { ck_assert_ldouble_nan(s21_asin(-5)); }
END_TEST

START_TEST(asin_8) {
  double x = 0.123456789012345678901234567890;
  ck_assert_ldouble_eq_tol(asin(x), s21_asin(x), S21_EPS);
}
END_TEST

START_TEST(asin_9) {
  double x = 1 + S21_EPS;
  ck_assert_ldouble_nan(s21_asin(x));
}
END_TEST

START_TEST(asin_10) {
  double x = -1 - S21_EPS;
  ck_assert_ldouble_nan(s21_asin(x));
}
END_TEST

START_TEST(asin_11) {
  double x = S21_NAN;
  ck_assert_ldouble_nan(s21_asin(x));
}
END_TEST

START_TEST(asin_12) {
  double x = S21_INF_POS;
  ck_assert_ldouble_nan(s21_asin(x));
}
END_TEST

START_TEST(asin_13) {
  double x = 1;
  ck_assert_ldouble_eq(s21_asin(x), asin(x));
}
END_TEST

START_TEST(atan_1) { ck_assert_double_eq_tol(s21_atan(-1), atan(-1), S21_EPS); }
END_TEST

START_TEST(atan_2) {
  ck_assert_double_eq(s21_atan(S21_INF_POS), atan(S21_INF_POS));
}
END_TEST

START_TEST(atan_3) {
  ck_assert_double_nan(s21_atan(S21_NAN));
  ck_assert_double_nan(atan(S21_NAN));
}
END_TEST

START_TEST(atan_4) {
  ck_assert_double_eq(s21_atan(S21_INF_NEG), atan(S21_INF_NEG));
}
END_TEST

START_TEST(atan_5) {
  ck_assert_double_eq_tol(s21_atan(14.96), atan(14.96), S21_EPS);
}
END_TEST

START_TEST(atan_6) {
  ck_assert_double_eq_tol(s21_atan(-25.1235), atan(-25.1235), S21_EPS);
}
END_TEST

START_TEST(atan_7) {
  ck_assert_double_eq_tol(s21_atan(0.23464), atan(0.23464), S21_EPS);
}
END_TEST

START_TEST(atan_8) { ck_assert_double_eq_tol(s21_atan(0), atan(0), S21_EPS); }
END_TEST

START_TEST(atan_9) { ck_assert_double_eq_tol(s21_atan(1), atan(1), S21_EPS); }
END_TEST

START_TEST(ceil_1) {
  ck_assert_double_eq_tol(s21_ceil(-0.1), ceil(-0.1), S21_EPS);
}
END_TEST

START_TEST(ceil_2) {
  ck_assert_double_eq_tol(s21_ceil(-213.3), ceil(-213.3), S21_EPS);
}
END_TEST

START_TEST(ceil_3) { ck_assert_double_eq_tol(s21_ceil(50), ceil(50), S21_EPS); }
END_TEST

START_TEST(ceil_4) {
  ck_assert_double_nan(s21_ceil(S21_NAN));
  ck_assert_double_nan(ceil(S21_NAN));
}
END_TEST

START_TEST(ceil_5) {
  ck_assert_double_eq_tol(s21_ceil(213.3), ceil(213.3), S21_EPS);
}
END_TEST

START_TEST(cos_1) {
  ck_assert_double_eq_tol(s21_cos(1200000), cos(1200000), S21_EPS);
}
END_TEST

START_TEST(cos_2) {
  ck_assert_ldouble_eq_tol(s21_cos(-14.96), cos(-14.96), S21_EPS);
}

END_TEST

START_TEST(cos_3) { ck_assert_double_eq_tol(s21_cos(0), cos(0), S21_EPS); }
END_TEST

START_TEST(cos_4) {
  ck_assert_double_eq_tol(s21_cos(S21_PI_2), cos(S21_PI_2), S21_EPS);
}
END_TEST

START_TEST(cos_5) {
  ck_assert_double_eq_tol(s21_cos(-S21_PI_2), cos(-S21_PI_2), S21_EPS);
}
END_TEST

START_TEST(cos_6) {
  ck_assert_double_eq_tol(s21_cos(S21_PI), cos(S21_PI), S21_EPS);
}
END_TEST

START_TEST(cos_7) {
  ck_assert_double_nan(s21_cos(S21_INF_POS));
  ck_assert_double_nan(cos(S21_INF_POS));
}
END_TEST

START_TEST(cos_8) {
  ck_assert_double_nan(s21_cos(S21_NAN));
  ck_assert_double_nan(cos(S21_NAN));
}
END_TEST

START_TEST(cos_9) {
  ck_assert_double_nan(s21_cos(S21_INF_NEG));
  ck_assert_double_nan(cos(S21_INF_NEG));
}
END_TEST

START_TEST(exp_1) { ck_assert_double_eq(s21_exp(25048.369), exp(25048.369)); }
END_TEST

START_TEST(exp_2) {
  ck_assert_double_eq_tol(s21_exp(-14.96), exp(-14.96), S21_EPS);
}
END_TEST

START_TEST(exp_3) {
  ck_assert_double_eq(s21_exp(S21_INF_POS), exp(S21_INF_POS));
}
END_TEST

START_TEST(exp_4) {
  ck_assert_double_eq(s21_exp(-S21_INF_NEG), exp(-S21_INF_NEG));
}
END_TEST

START_TEST(exp_5) { ck_assert_double_eq_tol(s21_exp(0), exp(0), S21_EPS); }
END_TEST

START_TEST(exp_6) { ck_assert_double_eq_tol(s21_exp(1), exp(1), S21_EPS); }
END_TEST

START_TEST(exp_7) { ck_assert_double_eq_tol(s21_exp(-1), exp(-1), S21_EPS); }
END_TEST

START_TEST(exp_8) {
  ck_assert_double_nan(s21_exp(S21_NAN));
  ck_assert_double_nan(exp(S21_NAN));
}
END_TEST

START_TEST(fabs_1) {
  ck_assert_double_eq_tol(s21_fabs(568.36), fabs(568.36), S21_EPS);
}
END_TEST

START_TEST(fabs_2) {
  ck_assert_double_eq_tol(s21_fabs(-14720.5689), fabs(-14720.5689), S21_EPS);
}
END_TEST

START_TEST(fabs_3) {
  ck_assert_double_eq(s21_fabs(S21_INF_POS), fabs(S21_INF_POS));
}
END_TEST

START_TEST(fabs_4) {
  ck_assert_double_eq(s21_fabs(S21_INF_NEG), fabs(S21_INF_NEG));
}
END_TEST

START_TEST(fabs_5) {
  ck_assert_double_nan(s21_fabs(S21_NAN));
  ck_assert_double_nan(fabs(S21_NAN));
}
END_TEST

START_TEST(fact_1) { ck_assert_double_eq(s21_factorial(7), 5040); }
END_TEST

START_TEST(fact_2) { ck_assert_double_eq(s21_factorial(1), 1); }
END_TEST

START_TEST(fact_3) { ck_assert_double_eq(s21_factorial(0), 1); }
END_TEST

START_TEST(fact_4) { ck_assert_double_eq(s21_factorial(11), 39916800); }
END_TEST

START_TEST(fact_5) { ck_assert_double_eq(s21_factorial(5), 120); }
END_TEST

START_TEST(floor_1) {
  ck_assert_double_eq_tol(s21_floor(-0.8), floor(-0.8), S21_EPS);
}
END_TEST

START_TEST(floor_2) {
  ck_assert_double_eq_tol(s21_floor(0.8), floor(0.8), S21_EPS);
}
END_TEST

START_TEST(floor_3) {
  ck_assert_double_eq_tol(s21_floor(-10.23), floor(-10.23), S21_EPS);
}
END_TEST

START_TEST(floor_4) {
  ck_assert_double_eq(s21_floor(S21_INF_POS), floor(S21_INF_POS));
}
END_TEST

START_TEST(floor_5) {
  ck_assert_double_eq(s21_floor(S21_INF_NEG), floor(S21_INF_NEG));
}
END_TEST

START_TEST(floor_6) {
  ck_assert_double_eq_tol(s21_floor(-1200), floor(-1200), S21_EPS);
}
END_TEST

START_TEST(floor_7) {
  ck_assert_double_nan(s21_floor(NAN));
  ck_assert_double_nan(floor(NAN));
}
END_TEST

START_TEST(fmod_1) {
  ck_assert_ldouble_eq_tol(s21_fmod(12.0, 4.0), fmod(12.0, 4.0), S21_EPS);
}
END_TEST

START_TEST(fmod_2) {
  ck_assert_ldouble_eq_tol(s21_fmod(0.5, 5.5), fmod(0.5, 5.5), S21_EPS);
}
END_TEST

START_TEST(fmod_3) { ck_assert_ldouble_nan(s21_fmod(S21_INF_POS, 5.5)); }
END_TEST

START_TEST(fmod_4) { ck_assert_ldouble_nan(s21_fmod(S21_INF_NEG, 5.5)); }
END_TEST

START_TEST(fmod_6) {
  ck_assert_ldouble_eq_tol(s21_fmod(5.8, S21_INF_POS), fmod(5.8, S21_INF_POS),
                           S21_EPS);
}
END_TEST

START_TEST(fmod_7) {
  ck_assert_ldouble_eq_tol(s21_fmod(5.8, S21_INF_NEG), fmod(5.8, S21_INF_NEG),
                           S21_EPS);
}
END_TEST

START_TEST(fmod_8) { ck_assert_ldouble_nan(s21_fmod(S21_NAN, 12.6)); }
END_TEST

START_TEST(fmod_9) { ck_assert_ldouble_nan(s21_fmod(5.5, S21_NAN)); }
END_TEST

START_TEST(log_1) {
  ck_assert_double_eq_tol(s21_log(26941.289), log(26941.289), S21_EPS);
}
END_TEST

START_TEST(log_2) {
  ck_assert_double_nan(s21_log(-12.36));
  ck_assert_double_nan(log(-12.36));
}
END_TEST

START_TEST(log_3) {
  ck_assert_double_eq(s21_log(S21_INF_POS), log(S21_INF_POS));
}
END_TEST

START_TEST(log_4) {
  ck_assert_double_nan(s21_log(S21_NAN));
  ck_assert_double_nan(log(S21_NAN));
}
END_TEST

START_TEST(log_5) {
  ck_assert_double_nan(s21_log(S21_INF_NEG));
  ck_assert_double_nan(log(S21_INF_NEG));
}
END_TEST

START_TEST(log_6) { ck_assert_double_eq(s21_log(0), log(0)); }
END_TEST

START_TEST(log_7) { ck_assert_double_eq(s21_log(1), log(1)); }
END_TEST
START_TEST(log_8) {
  ck_assert_double_eq_tol(s21_log(S21_EPS), log(S21_EPS), S21_EPS);
}
END_TEST

START_TEST(log_9) { ck_assert_double_eq(s21_log(S21_EXP), log(S21_EXP)); }
END_TEST

START_TEST(pow_1) {
  ck_assert_double_eq_tol(s21_pow(2904.169, 3), pow(2904.169, 3), S21_EPS);
}
END_TEST

START_TEST(pow_2) {
  ck_assert_double_eq_tol(s21_pow(-14.96, 4), pow(-14.96, 4), S21_EPS);
}
END_TEST

START_TEST(pow_3) {
  ck_assert_double_eq(s21_pow(S21_INF_POS, 10), pow(S21_INF_POS, 10));
}
END_TEST

START_TEST(pow_4) {
  ck_assert_double_eq(s21_pow(-S21_INF_NEG, -1), pow(-S21_INF_NEG, -1));
}
END_TEST

START_TEST(pow_6) {
  ck_assert_double_eq_tol(s21_pow(S21_PI, 3), pow(S21_PI, 3), S21_EPS);
}
END_TEST

START_TEST(pow_7) { ck_assert_double_eq(s21_pow(0, -1), pow(0, -1)); }
END_TEST

START_TEST(pow_8) {
  ck_assert_double_nan(s21_pow(S21_NAN, 20));
  ck_assert_double_nan(pow(S21_NAN, 20));
}
END_TEST

START_TEST(pow_9) { ck_assert_double_eq(s21_pow(0, 0), pow(0, 0)); }
END_TEST

START_TEST(pow_10) { ck_assert_double_eq(s21_pow(1, 5.4), pow(1, 5.4)); }
END_TEST

START_TEST(pow_11) { ck_assert_double_eq(s21_pow(2, 2), pow(2, 2)); }
END_TEST

START_TEST(pow_12) {
  ck_assert_double_nan(s21_pow(2, S21_NAN));
  ck_assert_double_nan(pow(2, S21_NAN));
}
END_TEST
START_TEST(pow_13) {
  ck_assert_double_eq(s21_pow(-1, S21_INF_NEG), pow(-1, S21_INF_NEG));
}
END_TEST
START_TEST(pow_14) {
  ck_assert_double_eq(s21_pow(-0.5, S21_INF_NEG), pow(-0.5, S21_INF_NEG));
}
END_TEST
START_TEST(pow_15) {
  ck_assert_double_eq(s21_pow(3, S21_INF_NEG), pow(3, S21_INF_NEG));
}
END_TEST
START_TEST(pow_16) {
  ck_assert_double_eq(s21_pow(-1, S21_INF_POS), pow(-1, S21_INF_POS));
}
END_TEST
START_TEST(pow_17) {
  ck_assert_double_eq(s21_pow(-0.5, S21_INF_POS), pow(-0.5, S21_INF_POS));
}
END_TEST
START_TEST(pow_18) {
  ck_assert_double_eq(s21_pow(3, S21_INF_POS), pow(3, S21_INF_POS));
}
END_TEST

START_TEST(sin_1) {
  ck_assert_double_eq_tol(s21_sin(1200000), sin(1200000), S21_EPS);
}
END_TEST

START_TEST(sin_2) {
  ck_assert_double_eq_tol(s21_sin(-14.96), sin(-14.96), S21_EPS);
}
END_TEST

START_TEST(sin_3) { ck_assert_double_eq_tol(s21_sin(0), sin(0), S21_EPS); }
END_TEST

START_TEST(sin_4) {
  ck_assert_double_eq_tol(s21_sin(S21_PI), sin(S21_PI), S21_EPS);
}
END_TEST

START_TEST(sin_5) {
  ck_assert_double_eq_tol(s21_sin(-S21_PI), sin(-S21_PI), S21_EPS);
}
END_TEST

START_TEST(sin_7) {
  ck_assert_double_nan(s21_sin(S21_INF_POS));
  ck_assert_double_nan(sin(S21_INF_POS));
}
END_TEST

START_TEST(sin_8) {
  ck_assert_double_nan(s21_sin(S21_NAN));
  ck_assert_double_nan(sin(S21_NAN));
}
END_TEST

START_TEST(sin_9) {
  ck_assert_double_nan(s21_sin(S21_INF_NEG));
  ck_assert_double_nan(sin(S21_INF_NEG));
}
END_TEST
START_TEST(sin_10) {
  ck_assert_double_eq_tol(s21_sin(S21_EPS), sin(S21_EPS), S21_EPS);
}
END_TEST

START_TEST(sqrt_1) {
  ck_assert_double_eq_tol(s21_sqrt(2.5), sqrt(2.5), S21_EPS);
}
END_TEST

START_TEST(sqrt_2) { ck_assert_double_nan(s21_sqrt(-5)); }
END_TEST

START_TEST(sqrt_3) { ck_assert_double_eq_tol(s21_sqrt(0), sqrt(0), S21_EPS); }
END_TEST

START_TEST(sqrt_4) {
  ck_assert_double_eq_tol(s21_sqrt(S21_PI), sqrt(S21_PI), S21_EPS);
}
END_TEST

START_TEST(sqrt_5) { ck_assert_double_nan(s21_sqrt(-S21_PI)); }
END_TEST

START_TEST(sqrt_6) {
  ck_assert_double_eq_tol(s21_sqrt(S21_PI), sqrt(S21_PI), S21_EPS);
}
END_TEST

START_TEST(sqrt_7) {
  ck_assert_double_eq(s21_sqrt(S21_INF_POS), sqrt(S21_INF_POS));
}
END_TEST

START_TEST(sqrt_8) {
  ck_assert_double_nan(s21_sqrt(S21_NAN));
  ck_assert_double_nan(sqrt(S21_NAN));
}
END_TEST

START_TEST(sqrt_9) {
  ck_assert_double_nan(s21_sqrt(S21_INF_NEG));
  ck_assert_double_nan(sqrt(S21_INF_NEG));
}

START_TEST(tan_1) { ck_assert_double_eq_tol(s21_tan(160), tan(160), S21_EPS); }
END_TEST
START_TEST(tan_2) {
  ck_assert_double_eq_tol(s21_tan(17.24), tan(17.24), S21_EPS);
}
END_TEST
START_TEST(tan_3) { ck_assert_double_eq_tol(s21_tan(0), tan(0), S21_EPS); }
END_TEST
START_TEST(tan_4) {
  ck_assert_double_eq_tol(s21_tan(S21_PI), tan(S21_PI), S21_EPS);
}
END_TEST
START_TEST(tan_5) {
  ck_assert_double_eq_tol(s21_tan(-S21_PI), tan(-S21_PI), S21_EPS);
}
END_TEST
START_TEST(tan_7) {
  ck_assert_double_nan(s21_tan(S21_INF_POS));
  ck_assert_double_nan(tan(S21_INF_POS));
}
END_TEST
START_TEST(tan_8) {
  ck_assert_double_nan(s21_tan(S21_NAN));
  ck_assert_double_nan(tan(S21_NAN));
}
END_TEST
START_TEST(tan_9) {
  ck_assert_double_nan(s21_tan(S21_INF_NEG));
  ck_assert_double_nan(tan(S21_INF_NEG));
}
END_TEST
START_TEST(tan_10) { ck_assert_double_nan(s21_tan(-S21_PI_2)); }
END_TEST

START_TEST(fmax_test) { ck_assert_double_eq(s21_fmax(1.5, 5.7), 5.7); }
END_TEST

Suite *abs_suite(void) {
  Suite *s;
  TCase *tc_core;
  s = suite_create("abs(x)");
  tc_core = tcase_create("core");
  tcase_add_test(tc_core, abs_1);
  tcase_add_test(tc_core, abs_2);
  tcase_add_test(tc_core, abs_3);
  tcase_add_test(tc_core, abs_4);
  tcase_add_test(tc_core, abs_5);
  suite_add_tcase(s, tc_core);
  return s;
}

Suite *acos_suite(void) {
  Suite *s;
  TCase *tc_core;
  s = suite_create("acos(x)");
  tc_core = tcase_create("core");
  tcase_add_test(tc_core, acos_1);
  tcase_add_test(tc_core, acos_2);
  tcase_add_test(tc_core, acos_3);
  tcase_add_test(tc_core, acos_4);
  tcase_add_test(tc_core, acos_5);
  tcase_add_test(tc_core, acos_6);
  tcase_add_test(tc_core, acos_7);
  tcase_add_test(tc_core, acos_8);
  tcase_add_test(tc_core, acos_9);
  suite_add_tcase(s, tc_core);
  return s;
}

Suite *asin_suite(void) {
  Suite *s;
  TCase *tc_core;
  s = suite_create("asin(x)");
  tc_core = tcase_create("core");
  tcase_add_test(tc_core, asin_1);
  tcase_add_test(tc_core, asin_2);
  tcase_add_test(tc_core, asin_3);
  tcase_add_test(tc_core, asin_4);
  tcase_add_test(tc_core, asin_5);
  tcase_add_test(tc_core, asin_6);
  tcase_add_test(tc_core, asin_7);
  tcase_add_test(tc_core, asin_8);
  tcase_add_test(tc_core, asin_9);
  tcase_add_test(tc_core, asin_10);
  tcase_add_test(tc_core, asin_11);
  tcase_add_test(tc_core, asin_12);
  tcase_add_test(tc_core, asin_13);
  suite_add_tcase(s, tc_core);
  return s;
}

Suite *atan_suite(void) {
  Suite *s;
  TCase *tc_core;
  s = suite_create("atan(x)");
  tc_core = tcase_create("core");
  tcase_add_test(tc_core, atan_1);
  tcase_add_test(tc_core, atan_2);
  tcase_add_test(tc_core, atan_3);
  tcase_add_test(tc_core, atan_4);
  tcase_add_test(tc_core, atan_5);
  tcase_add_test(tc_core, atan_6);
  tcase_add_test(tc_core, atan_7);
  tcase_add_test(tc_core, atan_8);
  tcase_add_test(tc_core, atan_9);
  suite_add_tcase(s, tc_core);
  return s;
}

Suite *ceil_suite(void) {
  Suite *s;
  TCase *tc_core;
  s = suite_create("ceil(x)");
  tc_core = tcase_create("core");
  tcase_add_test(tc_core, ceil_1);
  tcase_add_test(tc_core, ceil_2);
  tcase_add_test(tc_core, ceil_3);
  tcase_add_test(tc_core, ceil_4);
  tcase_add_test(tc_core, ceil_5);
  suite_add_tcase(s, tc_core);
  return s;
}

Suite *cos_suite(void) {
  Suite *s;
  TCase *tc_core;
  s = suite_create("cos(x)");
  tc_core = tcase_create("core");
  tcase_add_test(tc_core, cos_1);
  tcase_add_test(tc_core, cos_2);
  tcase_add_test(tc_core, cos_3);
  tcase_add_test(tc_core, cos_4);
  tcase_add_test(tc_core, cos_5);
  tcase_add_test(tc_core, cos_6);
  tcase_add_test(tc_core, cos_7);
  tcase_add_test(tc_core, cos_8);
  tcase_add_test(tc_core, cos_9);
  suite_add_tcase(s, tc_core);
  return s;
}

Suite *exp_suite(void) {
  Suite *s;
  TCase *tc_core;
  s = suite_create("exp(x)");
  tc_core = tcase_create("core");
  tcase_add_test(tc_core, exp_1);
  tcase_add_test(tc_core, exp_2);
  tcase_add_test(tc_core, exp_3);
  tcase_add_test(tc_core, exp_4);
  tcase_add_test(tc_core, exp_5);
  tcase_add_test(tc_core, exp_6);
  tcase_add_test(tc_core, exp_7);
  tcase_add_test(tc_core, exp_8);
  suite_add_tcase(s, tc_core);
  return s;
}

Suite *fabs_suite(void) {
  Suite *s;
  TCase *tc_core;
  s = suite_create("fabs(x)");
  tc_core = tcase_create("core");
  tcase_add_test(tc_core, fabs_1);
  tcase_add_test(tc_core, fabs_2);
  tcase_add_test(tc_core, fabs_3);
  tcase_add_test(tc_core, fabs_4);
  tcase_add_test(tc_core, fabs_5);
  suite_add_tcase(s, tc_core);
  return s;
}

Suite *fuct_suite(void) {
  Suite *s;
  TCase *tc_core;
  s = suite_create("fact(x)");
  tc_core = tcase_create("core");
  tcase_add_test(tc_core, fact_1);
  tcase_add_test(tc_core, fact_2);
  tcase_add_test(tc_core, fact_3);
  tcase_add_test(tc_core, fact_4);
  tcase_add_test(tc_core, fact_5);
  suite_add_tcase(s, tc_core);
  return s;
}

Suite *floor_suite(void) {
  Suite *s;
  TCase *tc_core;
  s = suite_create("floor(x)");
  tc_core = tcase_create("core");
  tcase_add_test(tc_core, floor_1);
  tcase_add_test(tc_core, floor_2);
  tcase_add_test(tc_core, floor_3);
  tcase_add_test(tc_core, floor_4);
  tcase_add_test(tc_core, floor_5);
  tcase_add_test(tc_core, floor_6);
  tcase_add_test(tc_core, floor_7);
  suite_add_tcase(s, tc_core);
  return s;
}

Suite *fmod_suite(void) {
  Suite *s;
  TCase *tc_core;
  s = suite_create("fmod(x)");
  tc_core = tcase_create("core");
  tcase_add_test(tc_core, fmod_1);
  tcase_add_test(tc_core, fmod_2);
  tcase_add_test(tc_core, fmod_3);
  tcase_add_test(tc_core, fmod_4);
  tcase_add_test(tc_core, fmod_6);
  tcase_add_test(tc_core, fmod_7);
  tcase_add_test(tc_core, fmod_8);
  tcase_add_test(tc_core, fmod_9);
  suite_add_tcase(s, tc_core);
  return s;
}

Suite *log_suite(void) {
  Suite *s;
  TCase *tc_core;
  s = suite_create("log(x)");
  tc_core = tcase_create("core");
  tcase_add_test(tc_core, log_1);
  tcase_add_test(tc_core, log_2);
  tcase_add_test(tc_core, log_3);
  tcase_add_test(tc_core, log_4);
  tcase_add_test(tc_core, log_5);
  tcase_add_test(tc_core, log_6);
  tcase_add_test(tc_core, log_7);
  tcase_add_test(tc_core, log_8);
  tcase_add_test(tc_core, log_9);

  // Установка времени ожидания для log_3 на 5 секунд
  tcase_set_timeout(tc_core, 5);

  suite_add_tcase(s, tc_core);
  return s;
}

Suite *pow_suite(void) {
  Suite *s;
  TCase *tc_core;
  s = suite_create("pow(x)");
  tc_core = tcase_create("core");
  tcase_add_test(tc_core, pow_1);
  tcase_add_test(tc_core, pow_2);
  tcase_add_test(tc_core, pow_3);
  tcase_add_test(tc_core, pow_4);
  tcase_add_test(tc_core, pow_6);
  tcase_add_test(tc_core, pow_7);
  tcase_add_test(tc_core, pow_8);
  tcase_add_test(tc_core, pow_9);
  tcase_add_test(tc_core, pow_10);
  tcase_add_test(tc_core, pow_11);
  tcase_add_test(tc_core, pow_12);
  tcase_add_test(tc_core, pow_13);
  tcase_add_test(tc_core, pow_14);
  tcase_add_test(tc_core, pow_15);
  tcase_add_test(tc_core, pow_16);
  tcase_add_test(tc_core, pow_17);
  tcase_add_test(tc_core, pow_18);
  suite_add_tcase(s, tc_core);
  return s;
}

Suite *sin_suite(void) {
  Suite *s;
  TCase *tc_core;
  s = suite_create("sin(x)");
  tc_core = tcase_create("core");
  tcase_add_test(tc_core, sin_1);
  tcase_add_test(tc_core, sin_2);
  tcase_add_test(tc_core, sin_3);
  tcase_add_test(tc_core, sin_4);
  tcase_add_test(tc_core, sin_5);
  tcase_add_test(tc_core, sin_7);
  tcase_add_test(tc_core, sin_8);
  tcase_add_test(tc_core, sin_9);
  tcase_add_test(tc_core, sin_10);
  suite_add_tcase(s, tc_core);
  return s;
}

Suite *sqrt_suite(void) {
  Suite *s;
  TCase *tc_core;
  s = suite_create("sqrt(x)");
  tc_core = tcase_create("core");
  tcase_add_test(tc_core, sqrt_1);
  tcase_add_test(tc_core, sqrt_2);
  tcase_add_test(tc_core, sqrt_3);
  tcase_add_test(tc_core, sqrt_4);
  tcase_add_test(tc_core, sqrt_5);
  tcase_add_test(tc_core, sqrt_6);
  tcase_add_test(tc_core, sqrt_7);
  tcase_add_test(tc_core, sqrt_8);
  tcase_add_test(tc_core, sqrt_9);
  suite_add_tcase(s, tc_core);
  return s;
}

Suite *tan_suite(void) {
  Suite *s;
  TCase *tc_core;
  s = suite_create("tan(x)");
  tc_core = tcase_create("core");
  tcase_add_test(tc_core, tan_1);
  tcase_add_test(tc_core, tan_2);
  tcase_add_test(tc_core, tan_3);
  tcase_add_test(tc_core, tan_4);
  tcase_add_test(tc_core, tan_5);
  tcase_add_test(tc_core, tan_7);
  tcase_add_test(tc_core, tan_8);
  tcase_add_test(tc_core, tan_9);
  tcase_add_test(tc_core, tan_10);
  suite_add_tcase(s, tc_core);
  return s;
}

Suite *fmax_suite(void) {
  Suite *s;
  TCase *tc_core;
  s = suite_create("fmax(x,y)");
  tc_core = tcase_create("core");
  tcase_add_test(tc_core, fmax_test);
  suite_add_tcase(s, tc_core);
  return s;
}

void case_test(Suite *s, int *fail) {
  SRunner *runner = srunner_create(s);
  srunner_run_all(runner, CK_NORMAL);
  *fail = srunner_ntests_failed(runner);
  srunner_free(runner);
}

int main() {
  int fail = 0;
  case_test(abs_suite(), &fail);
  case_test(acos_suite(), &fail);
  case_test(asin_suite(), &fail);
  case_test(atan_suite(), &fail);
  case_test(ceil_suite(), &fail);
  case_test(cos_suite(), &fail);
  case_test(exp_suite(), &fail);
  case_test(fabs_suite(), &fail);
  case_test(floor_suite(), &fail);
  case_test(fmod_suite(), &fail);
  case_test(fuct_suite(), &fail);
  case_test(log_suite(), &fail);
  case_test(pow_suite(), &fail);
  case_test(sin_suite(), &fail);
  case_test(sqrt_suite(), &fail);
  case_test(tan_suite(), &fail);
  case_test(fmax_suite(), &fail);
  return fail;
}
