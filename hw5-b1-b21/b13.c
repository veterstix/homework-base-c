#include "stdio.h"

int main(void) {
  int a;
  scanf("%d", &a);

  int even = 0;
  int odd = 0;
  while (a != 0) {
    int tmp = a % 10;
    if (tmp&1) {
      odd++;
    } else {
      even++;
    }
    a /= 10;
  }

  printf("%d %d\n", even, odd);;
  
  return 0;
}