#include "s21_math.h"

long double s21_asin(double x) {
  long double ans = x, y = x;
  long double i = 1;
  while (s21_fabs(ans) > S21_EPS) {
    if (x < -1 || x > 1) {
      y = S21_NAN;
      break;
    }
    if (x == 1 || x == -1) {
      y = S21_PI / 2 * x;
      break;
    }
    ans *= x * x * (2 * i - 1) * (2 * i - 1) / ((2 * i + 1) * 2 * i);
    i += 1;
    y += ans;
  }
  return y;
}