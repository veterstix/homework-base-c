// Составить рекурсивную функцию, печать всех чисел от N до 1

#include <stdio.h>

void rec(int n) {
  printf("%d ", n);
  if (n > 1) {
    rec(n-1);
  }
}

int main(void) {
  int n = 0;
  scanf("%d", &n);
  rec(n);
  return 0;
}