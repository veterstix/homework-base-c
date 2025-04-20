#include "stdio.h"

int equal_sum_and_mul(int x) {
  int sum = 0;
  int mul = 1;
  while (x != 0) {
    sum += x % 10;
    mul *= x % 10;
    x /= 10;
  }
  return sum == mul;
}

int main(void) {
  int a;
  scanf("%d", &a);

  int i = 10;
  int count = 0;
  while (i <= a) {
    if (equal_sum_and_mul(i)) {
      printf("%d ", i);
    }
    i++;
  }

  printf("\n");
  
  return 0;
}