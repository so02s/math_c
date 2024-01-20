#include "../s21_math.h"

long double s21_exp(double x) {
  long double res = 1, last_res = 1;
  long double now_step = 1, now_x = x, now_fact = 1;

  if (x == -0 || x == 0)
    res = 1;
  else if (s21_isinf(x) && x < 0)
    res = 0;
  else if (s21_isinf(x))
    res = S21_INF;
  else if (s21_isnan(x))
    res = S21_NAN;
  else
    do {
      last_res = res;
      res += now_x / now_fact;
      now_step++;
      now_x *= x;
      now_fact *= now_step;
    } while ((s21_fabs(res - last_res) >= PRECISION) && (res >= -100));
  if (res < 0) res = 0;

  return res;
}