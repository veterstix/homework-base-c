// Составить рекурсивную функцию, печать всех простых множителей числа.
#include <stdio.h>

void rec(int n, int divider) {
  if (n <= 1) {
    return;
  }
  if ((n%divider) == 0) {
    printf("%d ", divider);
    n/=divider;
  } else {
    divider++;
  }
  rec(n, divider);
}

int main(void) {
  int n = 0;
  scanf("%d", &n);
  rec(n, 2);
  return 0;
}