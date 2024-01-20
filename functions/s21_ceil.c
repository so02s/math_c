#include "../s21_math.h"

long double s21_ceil(double x) {
  long double result;
  if (x == S21_INF || x == S21_NEG_INF || x == S21_DBL_MAX) {
    result = x;
  } else {
    long double c = (long double)x - (int)x;
    if (c > 0)
      x = (x - c) + 1;
    else if (x < 0)
      x = (x + (-c));
    result = (long double)x;
  }
  return result;
}
