#include "../s21_math.h"

long double s21_floor(double x) {
  long double result = x;
  if (result != result) {
  } else if (result == S21_INF || result == S21_NEG_INF ||
             result == S21_DBL_MAX) {
  } else {
    long double c = result - (long long int)result;
    if (result > 0 && c > 0)
      result = (result - c);
    else if (result < 0 && c != 0)
      result = (result - c) - 1;
  }
  return result;
}
