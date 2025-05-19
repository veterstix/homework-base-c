// Описать функцию вычисления f(x) по формуле
// f(x)= x*x при -2 ≤ x < 2;
// x*x+4x+5 при x ≥ 2;
// 4 при x < -2.
// Используя эту функцию для n заданных чисел, вычислить f(x). Среди вычисленных значений найти наибольшее.
#include <stdio.h>

int f(int x) {
  if (x < -2) {
    return 4;
  }
  if (x >= 2) {
    return x * x + 4*x + 5;
  }
  return x * x;
}

int main(void) {
  int x = 0;
  int flag = 1;
  int max = 0;
  while (scanf("%d", &x) && x != 0) {
    int val = f(x);
    if (flag) {
      max = val;
      flag = 0;
    }

    if (val > max) {
      max = val;
    }
  }

  printf("%d", max);
  return 0;
}