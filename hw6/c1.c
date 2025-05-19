// Составить функцию, модуль числа и привести пример ее использования.

#include <stdio.h>

int myabs(int num) {
  if (num < 0) {
    return -num;
  }
  return num;
}

int main(void) {
  int num = 0;
  scanf("%d", &num);
  printf("%d\n", myabs(num));
  return 0;
}