#include "s21_math.h"

long double s21_pow(double base, double exp) {
  unsigned int e = 0;
  long double result = 1.0;

  if (base == 0) {
    if (exp > 0) {
      result = 0;
    } else if (exp == 0) {
      result = 1;
    } else if (exp != exp) {
      result = S21_NAN;
    } else {
      result = S21_INF_POS;
    }
  } else if (base == 1) {
    result = 1;
  } else if (exp == (int)(e = (int)exp)) {
    if ((int)e < 0) {
      e = -e;
      base = 1 / base;
    }
    for (int i = 0; i < (int)e; i++) {
      result *= base;
    }
  } else if (base != base) {
    result = S21_NAN;
  } else if (exp == S21_INF_NEG) {
    if (base == -1) {
      result = 1;
    } else if (base < 1 && base > -1) {
      result = S21_INF_POS;
    } else {
      result = 0;
    }
  } else if (exp == S21_INF_POS) {
    if (base == -1) {
      result = 1;
    } else if (base < 1 && base > -1) {
      result = 0;
    } else {
      result = S21_INF_POS;
    }
  } else {
    result = s21_exp(s21_log(base) * exp);
  }
  return result;
}