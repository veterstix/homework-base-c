// Перевести число N в систему счисления P
#include "stdio.h"

void convert(int n, int p) {
  int res = 0;
  int v = 1;
  while (n > 0) {
    res += n%p * v;
    v *= 10;
    n /= p;
  }
  printf("%d\n", res);
}

int main(void) {
  int n, p;
  scanf("%d %d", &n, &p);
  convert(n, p);
  return 0;
}