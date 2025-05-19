// Написать функцию, которая возвращает среднее арифметическое двух переданных ей аргументов (параметров).
#include <stdio.h>

int middle(int a, int b) {
  return (a+b)/2;
}

int main(void) {
  int a, b = 0;
  scanf("%d %d", &a, &b);
  printf("%d\n", middle(a, b));
  return 0;
}