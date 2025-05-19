#include "stdio.h"

void print_simple(int n) {
  int divider = 2;
  while (n != 1) {
    if (n%divider ==0) {
      printf("%d ", divider);
      n /= divider;
    } else {
      divider++;
    }
  }
}

int main(void) {
  int n;
  scanf("%d", &n);
  print_simple(n);
  return 0;
}