// // Составить функцию, которая вычисляет синус как сумму ряда (с точностью 0.001)
// // sin(x) = x - x3/3! + x5/5! - x7/7! + ...(x в радианах)
// // float sinus(float x)

#include <stdio.h>
#include <math.h>

#define eps 1e-3

double sinus(double x) {
  double res = 0.0;
  double xn = x;
  int i = 1;

  while (fabs(xn) > eps) {
    res += xn;
    xn *= -1.0 * x * x / ((2 * i) * (2 * i + 1));
    i++;
  }

  return res;
}

int main(void) {
  double num = 0;
  scanf("%lf", &num);
  num *= M_PI/180.0;
  printf("%.3f\n", sinus(num));
  int k = 1;
  return 0;
}