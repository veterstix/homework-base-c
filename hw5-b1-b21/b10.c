#include "stdio.h"

int main(void) {
  int a;
  scanf("%d", &a);

  int pred = 10;
  while (a != 0) {
    if (a % 10 >= pred) {
      printf("NO\n");
      return 0;
    }
    pred = a % 10;
    a /= 10;
  }

  printf("YES\n");;
  
  return 0;
}