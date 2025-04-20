#include "stdio.h"

int main(void) {
  int a;
  scanf("%d", &a);

  int pred = 0;
  int k = 0;
  while (a != 0) {
    if (k != 0 && pred == a % 10) {
      printf("YES\n");
      return 0;
    }
    pred = a % 10;
    a /= 10;
    k++;
  }

  printf("NO\n");;
  
  return 0;
}