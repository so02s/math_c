#include "../s21_math.h"

long double s21_cos(double x) {
  long double cur = 1;
  if (x == 0 || x == -0)
    cur = 1;
  else if (s21_isinf(x) || s21_isnan(x))
    cur = S21_NAN;
  else {
    cur = x;
    while (cur > 2 * S21_PI || cur < S21_PI * -2)
      if (cur > 2 * S21_PI)
        cur -= 2 * S21_PI;
      else
        cur += 2 * S21_PI;
    cur = ((cur > S21_PI / 2 && cur < 3 * S21_PI / 2) ||
           (cur < -S21_PI / 2 && cur > -3 * S21_PI / 2))
              ? -s21_sqrt(1 - s21_pow(s21_sin(x), 2))
              : s21_sqrt(1 - s21_pow(s21_sin(x), 2));  // <==== s21
  }
  return cur;
}
