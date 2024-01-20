#include "../s21_math.h"

long double s21_asin(double x) {
  long double res = 0, res_prev = 2;
  long double a = 0, b = 0, c = 0, d = 0, e = 0;
  int n = 0;
  if (x == 0 || x == -0)
    res = x;
  else if (x > 1 || x < -1 || s21_isnan(x))
    res = S21_NAN;
  else if (x == 1 || x == -1)
    res = x * (S21_PI / 2);
  else if (x < 0.8 && x > -0.8)
    do {
      res_prev = res;
      a = s21_factorial(2 * n);
      b = s21_pow(2, 2 * n);
      c = s21_pow(s21_factorial(n), 2);
      e = 2 * n + 1;
      d = s21_pow(x, e);
      res += (a * d) / (b * c * e);
      n++;
    } while (s21_fabs(res - res_prev) > PRECISION);
  else {
    res = s21_acos(s21_sqrt(1 - x * x));
    res = (x < 0) ? -res : res;
  }
  return res;
}
