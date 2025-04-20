#include <stdio.h>

int main(void) {
  int a;
  scanf("%d", &a);
  int mul = 1;
  while (a != 0) {
    mul *= a % 10;
    a /= 10;
  }
  printf("%d\n", mul);
  return 0;
}