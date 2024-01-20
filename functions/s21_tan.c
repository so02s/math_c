#include "../s21_math.h"

long double s21_tan(double x) {
  long double res = 0;
  if (x == 0 || x == -0)
    res = x;
  else if (s21_isinf(x) || s21_isnan(x))
    res = S21_NAN;
  else
    res = s21_sin(x) / s21_cos(x);
  return res;
}
