#include "stdio.h"

int main(void) {
  int a;
  scanf("%d", &a);

  int i = 1;
  while (i <= a) {
    printf("%d %d %d\n", i, i*i, i*i*i);
    i++;
  }
  
  return 0;
}