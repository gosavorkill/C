#include "s21_math.h"

long double s21_atan(double x) {
  long double result = 0;
  long double tmp = 0;
  if (x == S21_INF_POS)
    result = S21_PI / 2.0;
  else if (x == S21_INF_NEG)
    result = -S21_PI / 2.0;
  else if (x == 1)
    result = S21_PI / 4.0;
  else if (x == -1)
    result = -S21_PI / 4.0;
  else {
    if (x > -1 && x < 1)
      result = x;
    else
      result = 1.0 / x;

    if (x > -1 && x < 1)
      tmp = 1;
    else
      tmp = -1;

    for (int i = 1; i < 5000; i++) {
      double numerator = s21_pow(-1, i) * s21_pow(x, (1 + 2 * i) * tmp);
      double denominator = 1 + 2 * i;
      result += numerator / denominator;
    }
    if (x < -1 || x > 1) result = (S21_PI * s21_fabs(x) / (2 * x)) - result;
  }

  return result;
}