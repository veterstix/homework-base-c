#include "stdio.h"

int nod(int a, int b) {
  while (b != 0) {
    int tmp = a;
    a = b;
    b = tmp % b;
  }
  return a;
}

int main(void) {
  int a, b;
  scanf("%d %d", &a, &b);
  printf("%d\n", nod(a,b));
  return 0;
}