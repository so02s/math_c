#include "../s21_math.h"

long double s21_atan(double x) {
  long double res = 0, res_prev = 0;
  long double a = 0, b = 0, c = 0;
  int n = 1;
  if (x == -0 || x == 0)
    res = x;
  else if (s21_isinf(x))
    res = (x > 0) ? S21_PI / 2 : -S21_PI / 2;
  else if (s21_isnan(x))
    res = S21_NAN;
  else if (x < 1 && x > -1)
    do {
      res_prev = res;
      a = s21_pow(-1, n - 1);
      c = 2 * n - 1;
      b = s21_pow(x, c);
      res += (a * b) / c;
      n++;
    } while (s21_fabs(res - res_prev) > PRECISION);
  else
    res = s21_asin(x / (s21_sqrt(x * x + 1)));
  return res;
}