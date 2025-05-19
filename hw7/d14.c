// Печать всех нечетных

#include <stdio.h>

void rec(void) {
  int n = 0;
  scanf("%d", &n);
  
  if (n == 0) {
    return;
  }
  if (n&1) {
    printf("%d ", n);
  }
  rec();
}

int main(void) {
  rec();
  return 0;
}