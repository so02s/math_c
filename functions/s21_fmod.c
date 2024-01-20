#include "../s21_math.h"

long double s21_fmod(double x, double y) {
  long double res = 0;
  if (y == 0 || y == -0)
    res = S21_NAN;
  else if (x == 0 || x == -0)
    res = x;
  else if (x == S21_INF || x == S21_NEG_INF)
    res = S21_NAN;
  else if (x == S21_NAN || y == S21_NAN)
    res = S21_NAN;
  else if (y == S21_INF || y == S21_NEG_INF)
    res = x;
  else
    res = x - ((int)(x / y) * y);
  return res;
}