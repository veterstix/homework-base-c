#include "stdio.h"

int main(void) {
  int a, b;
  scanf("%d %d", &a, &b);

  int sum = 0;
  while (a <= b) {
    sum += a*a;
    a++;
  }
  printf("%d\n", sum);
  
  return 0;
}