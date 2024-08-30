#include "s21_math.h"

int s21_isinf(double x) {
  return !s21_isnan(x) && s21_isnan(s21_abs(x) - s21_abs(x));
}