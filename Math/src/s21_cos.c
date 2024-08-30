#include "s21_math.h"

long double s21_cos(double x) {
  long double result = S21_NAN;
  if (x == S21_PI || x == -S21_PI)
    result = -1;
  else if (x == 0 || x == 2 * S21_PI || x == -2 * S21_PI)
    result = 1;
  else if (x != S21_INF_NEG && x != S21_INF_POS) {
    x = s21_fmod(x, 2 * S21_PI);
    if (x < 0) x += 2 * S21_PI;

    if (x < S21_PI / 2) {
      result = s21_sin(S21_PI / 2 - x);
    } else if (x == S21_PI_2 || x == -S21_PI_2) {
      result = 0;
    } else if (x <= S21_PI) {
      result = -s21_sin(x - S21_PI / 2);
    } else if (x <= 3 * S21_PI / 2) {
      result = -s21_sin(S21_PI / 2 - (x - S21_PI));

    } else {
      result = s21_sin(x - 3 * S21_PI / 2);
    }
  }

  return result;
}
