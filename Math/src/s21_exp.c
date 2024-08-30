#include <float.h>

#include "s21_math.h"

long double s21_exp(double x) {
  if (s21_isnan(x) || s21_isinf(x)) return 0.0 / 0.0;
  long double addens = 1;
  long double sum = 1;
  long double i = 1;
  while (s21_fabs(addens) > S21_EPS) {
    addens *= x / i;
    i += 1;
    sum += addens;
    if (sum > DBL_MAX) {
      sum = S21_INF_POS;
      break;
    }
  }
  return sum;
}