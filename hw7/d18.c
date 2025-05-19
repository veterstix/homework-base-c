// d18 нету

#include <stdio.h>

void rec(int n) {
  if (n == 0) {
    return;
  }
  rec(n-1);
  printf("%d ", n);
  return;
}

int main(void) {
  int n = 0;
  scanf("%d", &n);
  rec(n);
  return 0;
}