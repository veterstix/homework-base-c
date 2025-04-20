#include "stdio.h"

int main(void) {
  int a, b, c;
  scanf("%d %d %d", &a, &b, &c);
  if (a > b) {
    printf("Above\n"); 
  } else if (a < b) {
    printf("Less\n");
  } else {
    printf("Equal\n");
  }
  return 0;
}