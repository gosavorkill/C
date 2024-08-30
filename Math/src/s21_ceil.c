#include "s21_math.h"

long double s21_ceil(double x) {
  long double ans = s21_floor(x);
  if (s21_isnan(x))
    ans = (0. / 0.);
  else {
    if (ans != x) ans += 1;
  }
  return ans;
}
