// Дано натуральное число N. Вычислите сумму его цифр.
// Необходимо составить рекурсивную функцию.

#include <stdio.h>

int sum_digits(int n) {
  if (n <= 0) {
    return 0;
  }
  return n%10 + sum_digits(n/10);
}

int main(void) {
  int n = 0;
  scanf("%d", &n);
  int ans = sum_digits(n);
  printf("%d\n", ans);
  return 0;
}