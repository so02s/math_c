#include "../s21_math.h"

long double s21_log_checker(double x);

long double s21_log(double z) {
  long double res = s21_log_checker(z);
  if (res != -1) return res;
  long double x = (z - 1) / (z + 1);
  long double last_res, now_step = 3, now_x = x * x * x;
  res = x;
  do {
    last_res = 2 * res;
    res += now_x / now_step;
    now_x *= x * x;
    now_step += 2;
  } while (s21_fabs(2 * res - last_res) >= PRECISION);
  return 2 * res;
}

long double s21_log_checker(double x) {
  long double res = -1;
  if (s21_isnan(x) || x < 0) {
    res = S21_NAN;
  } else if (s21_isinf(x)) {
    res = S21_INF;
  } else if (x == 0.0 || x == -0.0) {
    res = S21_NEG_INF;
  } else if (x == 1) {
    res = 0;
  }
  return res;
}