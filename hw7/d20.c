// Написать рекурсивную функцию возведения целого числа n в степень p.

#include <stdio.h>

int recurs_power(int n, int p) {
  if (p == 0) {
    return 1;
  }
  return n * recurs_power(n, p-1);
}

int main(void) {
  int n, p = 0;
  scanf("%d %d", &n, &p);
  printf("%d", recurs_power(n, p));
  return 0;
}