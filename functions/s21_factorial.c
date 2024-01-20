#include "../s21_math.h"

long double s21_factorial(size_t x) {
  long double res = 1;
  for (size_t i = 1; i <= x; i++) res *= i;
  return res;
}