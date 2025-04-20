#include "stdio.h"

int main(void) {
  int a;
  scanf("%d", &a);

  int max = -1;
  int min = 10;
  while (a != 0) {
    int tmp = a % 10;
    if (max < tmp) {
      max = tmp;
    }
    if (min > tmp) {
      min = tmp;
    }
    a /= 10;
  }

  printf("%d %d\n", min, max);;
  
  return 0;
}