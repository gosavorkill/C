#include "s21_math.h"

long double s21_sin(double x) {
  long double result = 0.0;
  long double tmp = x;

  if (x == 0.0) {
    result = 0.0;
  } else if (x != S21_INF_NEG && x != S21_INF_POS) {
    x = s21_fmod(x, 2 * S21_PI);
    tmp = x;

    for (int i = 1; i <= 16; ++i) {
      result += tmp;
      tmp *= (-1.0) * x * x / ((2 * i) * (2 * i + 1));
    }
  } else {
    if (s21_fabs(x - S21_PI) <= 1e-9) {
      result = 0.0;
    } else if (s21_fabs(x + S21_PI) <= 1e-9) {
      result = 0.0;
    } else {
      result = S21_NAN;
    }
  }

  return result;
}
