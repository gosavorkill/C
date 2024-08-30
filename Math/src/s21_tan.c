#include "s21_math.h"

long double s21_tan(double x) {
  double result = 0;
  if (s21_cos(x) == 0)
    result = S21_NAN;
  else {
    result = s21_sin(x) / s21_cos(x);
  }

  return result;
}