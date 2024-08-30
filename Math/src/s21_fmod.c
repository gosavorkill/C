#include "s21_math.h"

long double s21_fmod(double x, double y) {
  long double res = 0;
  long int n = x / y;
  if (y == 0.0 || x == S21_INF_POS || x == S21_INF_NEG) {
    res = S21_NAN;
  } else if (y == S21_INF_POS || y == S21_INF_NEG) {
    res = x;
  } else {
    res = x - (n * y);
  }
  return res;
}