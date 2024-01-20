#include "../s21_math.h"

long double s21_sin(double x) {
  long double cur = 0, tt = x;
  if (x == 0 || x == -0)
    cur = x;
  else if (s21_isinf(x) || s21_isnan(x))
    cur = S21_NAN;
  else {
    while (tt > 2 * S21_PI || tt < S21_PI * -2)
      if (tt > 2 * S21_PI)
        tt -= 2 * S21_PI;
      else
        tt += 2 * S21_PI;
    cur = tt;
    int n = 3;
    long double step = -s21_pow(tt, n) / s21_factorial(n);
    long double lstep = cur + 1;
    while (!(cur - lstep < 1e-10 && cur - lstep > -1e-10)) {
      lstep = cur;
      cur += step;
      n += 2;
      step = ((n - 3) / 2 % 2 == 1 ? s21_pow(tt, n) : -s21_pow(tt, n)) /
             s21_factorial(n);
    }
  }
  return cur;
}
