// Составить функцию, которая определяет сумму всех чисел от 1 до N

#include <stdio.h>

int sum(int num) {
  int sum = 0;
  for (int i = num; i >= 0; i--) {
    sum += i;
  }
  return sum;
}

int main(void) {
  int num = 0;
  scanf("%d", &num);
  printf("%d\n", sum(num));
  return 0;
}