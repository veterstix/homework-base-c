#include "stdio.h"

int main(void) {
  int a;
  scanf("%d", &a);
  int arr[10];

  while (a != 0) {
    if (arr[a % 10] == 1) {
      printf("YES\n");
      return 0;
    } else {
      arr[a % 10] = 1;
    }
    a /= 10;
  }

  printf("NO\n");;
  
  return 0;
}