// Дано натуральное число N. Посчитать количество «1» в двоичной записи числа.

#include <stdio.h>

int rec(int n) {
  if (n == 0) {
    return n%2;
  }
  return n%2 + rec(n/2);
}

int main(void) {
  int n = 0;
  scanf("%d", &n);
  printf("%d",rec(n));
  return 0;
}