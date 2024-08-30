#include "s21_math.h"

long double s21_floor(double x) {
  long double result = 0.0;
  if (x != x) {
    result = S21_NAN;
  } else if (x == S21_INF_POS) {
    result = S21_INF_POS;
  } else if (x == S21_INF_NEG) {
    result = S21_INF_NEG;
  } else {
    result = (int)x;
    if (x < 0 && (x != (int)x)) {
      result -= 1;
    }
  }
  return result;
}