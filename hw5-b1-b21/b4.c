#include "stdio.h"

int main(void) {
  int a;
  scanf("%d", &a);

  int count = 0;
  while (a != 0) {
    a /= 10;
    count++;
  }

  count == 3 ? printf("YES\n") : printf("NO\n");
  
  return 0;
}