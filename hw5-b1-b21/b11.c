#include "stdio.h"

int main(void) {
  int a;
  scanf("%d", &a);

  int res = 0;
  while (a != 0) {
    res = res * 10 + a % 10;
    a /= 10;
  }

  printf("%d\n", res);;
  
  return 0;
}