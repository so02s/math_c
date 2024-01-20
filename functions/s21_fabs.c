#include "../s21_math.h"

long double s21_fabs(double x) {
  if (x < 0)
    x = -x;
  else if (x >= 0)
    x = x;
  return (long double)x;
}
