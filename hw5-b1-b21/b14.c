#include "stdio.h"

int main(void) {
  int a;
  int count = 0;
  while (scanf("%d", &a) && a != 0) {
    count++;
  }
  printf("%d\n", count);
  
  return 0;
}