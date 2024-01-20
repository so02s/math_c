#include "../s21_math.h"

long double s21_acos(double x) {
  long double res = 0;
  if (x == 1)
    res = 0;
  else if (x > 1 || x < -1 || s21_isnan(x))
    res = S21_NAN;
  else
    res = S21_PI / 2 - s21_asin(x);
  return res;
}
