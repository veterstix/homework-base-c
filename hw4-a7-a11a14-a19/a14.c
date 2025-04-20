#include <stdio.h>

int main(void) {
  int a;
  scanf("%d", &a);
  int max = 1 << 31;
  while (a != 0) {
    int tmp = a % 10;
    if (tmp > max) {
      max = tmp;
    }
    a /= 10;
  }
  printf("%d\n", max);
  return 0;
}