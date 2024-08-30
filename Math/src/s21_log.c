#include "s21_math.h"

long double s21_log(double x) {
  long double result = 0.0;
  int exp = 0, del = 0;
  if (x < 0 || x != x) {
    result = S21_NAN;
  } else if (x == S21_INF_POS) {
    result = S21_INF_POS;
  } else if (x == 0) {
    result = S21_INF_NEG;
  } else if (x == S21_EXP) {
    result = 1;
  } else {
    if (x > 2) {
      while (x > 1) {
        x /= 10;
        exp++;
      }
    } else if (x < 1) {
      while (x * 10 < 1) {
        x *= 10;
        exp--;
      }
    }
    while (x >= 2) {
      x /= 2;
      del++;
    }
    result = exp * S21_LN10 + del * S21_LOG_2;
    double res_lg = 0.0, a = 1.0;
    int b = 1, c = 1;
    while (s21_fabs(a) > S21_EPS) {
      a *= x - 1.0;
      res_lg += c * a / b;
      b++;
      c *= -1;
    }
    result += res_lg;
  }
  return result;
}
