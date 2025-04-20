#include "stdio.h"

int main(void) {
  int a;
  scanf("%d", &a);

  int flag = 0;
  while (a != 0) {
    int v = a % 10;
    if (v&1) {
        flag = 1;
    }
    if (flag) {
      printf("NO\n");
      return 0;
    }
    a /= 10;
  }

  printf("YES\n");
  
  return 0;
}