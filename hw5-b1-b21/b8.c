#include "stdio.h"

int main(void) {
  int a;
  scanf("%d", &a);

  int nine = 0;
  while (a != 0) {
    if (a % 10 == 9) {
        nine++;
    }
    a /= 10;
  }

  nine == 1 ? printf("YES\n") : printf("NO\n");
  
  return 0;
}