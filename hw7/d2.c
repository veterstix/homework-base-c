// Составить рекурсивную функцию, которая определяет сумму всех чисел от 1 до N

#include <stdio.h>

int rec(int n) {
  if (n == 1) {
    return 1;
  }
  return n + rec(n-1);
}

int main(void) {
  int n = 0;
  scanf("%d", &n);
  int ans = rec(n);
  printf("%d\n", ans);
  return 0;
}