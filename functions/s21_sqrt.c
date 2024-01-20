#include "../s21_math.h"

long double s21_sqrt(double x) {
  long double res = 0;
  if (x < -0)
    res = S21_NAN;
  else if (x == -0 || x == 0 || s21_isinf(x))
    res = x;
  else if (s21_isnan(x))
    res = S21_NAN;
  else
    res = s21_pow(2, 0.5 * s21_log2(x));
  return res;
}
