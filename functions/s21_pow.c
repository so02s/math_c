#include "../s21_math.h"

long double zero_pow(double base, double exp);
long double inf_base(double base, double exp);
long double s21_pow_check_limits(double base, double exp);

long double s21_pow(double base, double exp) {
  int t = 0;
  long double res = s21_pow_check_limits(base, exp);
  if (res == -1) {
    if (s21_fmod(exp, 1.0)) {
      res = s21_exp(exp * s21_log(base));
    } else {
      t = (exp < 0) ? 1 : 0;
      exp = (exp < 0) ? -exp : exp;
      while (exp > 0) {
        if (s21_fmod(exp, 2)) {
          res *= base;
          exp--;
        } else {
          base *= base;
          exp /= 2;
        }
      }
      res = (t) ? -1.0 / res : -res;
    }
  }
  return res;
}

long double s21_pow_check_limits(double base, double exp) {
  long double res = -1;
  if (base < 0 && !s21_isinf(exp) && s21_fmod(exp, 1))
    res = S21_NAN;
  else if (base == 0.0 || base == -0.0)
    res = zero_pow(base, exp);
  else if (base == -1 && s21_isinf(exp) == 1)
    res = 1;
  else if (base == 1 || exp == -0.0 || exp == 0.0)
    res = 1;
  else if (!s21_isinf(base) && base < 0 && !s21_isinf(exp) && s21_fmod(exp, 1))
    res = S21_NAN;
  else if (exp == S21_NEG_INF) {
    if (s21_isinf(base) || s21_abs(base) > 1)
      res = 0;
    else
      res = S21_INF;
  } else if (exp == S21_INF) {
    if (s21_isinf(base) || s21_abs(base) > 1)
      res = S21_INF;
    else
      res = 0;
  } else if (s21_isinf(base))
    res = inf_base(base, exp);
  else if ((s21_isnan(base) || s21_isnan(exp)) && res == -1)
    res = S21_NAN;
  return res;
}

long double zero_pow(double base, double exp) {
  long double res = S21_NAN;
  if (!s21_isinf(exp)) {
    if (exp == 0)
      res = 1;
    else if (exp < 0 && !s21_fmod(exp, 2)) {
      if (base == 0)
        res = S21_INF;
      else
        res = S21_NEG_INF;
    } else if (exp < 0 && (s21_fmod(exp, 2) || s21_fmod(exp, 1)))
      res = S21_INF;
    else if (exp == S21_NEG_INF)
      res = S21_INF;
    else if (exp > 0 && s21_fmod(exp, 2))
      res = base;
    else if (exp > 0 && (s21_fmod(exp, 1) || !s21_fmod(exp, 2)))
      res = 0.0;
  } else {
    if (exp == S21_NEG_INF)
      res = S21_INF;
    else
      res = 0.0;
  }
  return res;
}

long double inf_base(double base, double exp) {
  long double res = S21_NAN;
  if (base == S21_NEG_INF) {
    if (s21_fmod(exp, 2) && !s21_fmod(exp, 1)) {
      if (exp < 0)
        res = -0.0;
      else
        res = S21_NEG_INF;
    } else if (!s21_fmod(exp, 2) || s21_fmod(exp, 1)) {
      if (exp < 0)
        res = 0.0;
      else
        res = S21_INF;
    }
  } else {
    if (exp < 0)
      res = 0.0;
    else
      res = S21_INF;
  }
  if (s21_isnan(res) && s21_isnan(exp)) res = exp;
  return res;
}