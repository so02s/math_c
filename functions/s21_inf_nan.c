#include "../s21_math.h"

int c = 3;

int s21_isinf(double x) { return (x == S21_INF || x == S21_NEG_INF); }

int s21_isnan(double x) { return (x != x); }