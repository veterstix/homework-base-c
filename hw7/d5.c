// Перевести натуральное число в двоичную систему счисления. Необходимо реализовать рекурсивную функцию.
#include <stdio.h>
#include <stdint.h>

void rec(uint64_t n) {
  if (n >= 2) {
    rec(n/2);
  }
  printf("%ld", n%2);
}

int main(void) {
  uint64_t n = 0;
  scanf("%ld", &n);
  rec(n);
  printf("\n");
  return 0;
}