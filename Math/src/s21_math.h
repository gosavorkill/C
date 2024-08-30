#ifndef S21_MATH_H
#define S21_MATH_H

#define S21_PI 3.14159265358979323846264338327950288
#define S21_PI_2 1.57079632679489661923132169163975144
#define S21_EPS 1e-9
#define S21_INF_NEG -1.0 / 0.0
#define S21_INF_POS 1.0 / 0.0
#define S21_EXP 2.71828182845904523536
#define S21_NAN 0.0 / 0.0
#define S21_LN10 2.30258509299404568402
#define S21_LOG_2 0.69314718056
#define S21_2PI 6.2831853071795864768

int s21_abs(int x);

long double s21_ceil(double x);

long double s21_exp(double x);

long double s21_fabs(double x);

long double s21_floor(double x);

long double s21_fmod(double x, double y);

long double s21_log(double x);

long double s21_factorial(long long x);

int s21_isnan(double x);

int s21_isinf(double x);

double s21_fmax(double a, double x);

long double s21_sqrt(double x);

long double s21_pow(double base, double exp);

long double s21_sin(double x);

long double s21_cos(double x);

long double s21_acos(double x);

long double s21_asin(double x);

long double s21_atan(double x);

long double s21_tan(double x);

#endif