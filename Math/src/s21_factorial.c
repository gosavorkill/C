#include "s21_math.h"

long double s21_factorial(long long x) {
  if (x < 0) return 0;
  if (x == 0) return 1;
  return x * s21_factorial(x - 1);
}
