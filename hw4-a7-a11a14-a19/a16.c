#include "stdio.h"

int main(void) {
  #define COUNT 3
  int pred = 1 << 31;
  int curr;
  for (int i = 0; i < COUNT; i++) {
    scanf("%d", &curr);
    if (curr <= pred) {
      printf("NO");
      return 0;
    }
    pred = curr;
  }
  printf("YES\n");
  return 0;
}