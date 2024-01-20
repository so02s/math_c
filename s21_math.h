#ifndef S21_MATH_H
#define S21_MATH_H

#include <stdio.h>
#include <stdlib.h>

#define PRECISION 1e-20
#define PRECISION_test 1e-6
#define S21_DBL_MAX 1.79769e+308
#ifndef HUGE_VALF
#define HUGE_VALF __builtin_huge_valf()
#endif
#define S21_PI 3.14159265359
#define S21_NAN __builtin_nanf("0x7fc00000")
#define S21_INF HUGE_VALF
#define S21_NEG_INF S21_INF*(-1)

// вспомогательные функции
int s21_isinf(double x);
int s21_isinff(float x);
int s21_isnan(double x);
int s21_isnanf(float x);
long double s21_factorial(size_t x);  // ???
long double s21_log2(double n);
// <<===== rewrite facttorial in func

// основные функции
int s21_abs(int x);                            // 1 + ?
long double s21_acos(double x);                // 2 + ?
long double s21_asin(double x);                // 3 + ?
long double s21_atan(double x);                // 4 + ?
long double s21_ceil(double x);                // 5 + ?
long double s21_cos(double x);                 // 6 + ?
long double s21_exp(double x);                 // 7 + ?
long double s21_fabs(double x);                // 8 + ?
long double s21_floor(double x);               // 9 + ?
long double s21_fmod(double x, double y);      // 10 +? ?
long double s21_log(double x);                 // 11 + ?
long double s21_pow(double base, double exp);  // 12 + ?
long double s21_sin(double x);                 // 13 + ?
long double s21_sqrt(double x);                // 14 + ?
long double s21_tan(double x);                 // 15 + ?

#endif