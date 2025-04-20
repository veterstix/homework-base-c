#include "stdio.h"

int main(void) {
  int a;
  int count = 0;
  while (scanf("%d", &a) && a != 0) {
    if ((a&1) == 0) { // attention!! priority operators 
      count++;
    }
  }
  printf("%d\n", count);
  
  return 0;
}