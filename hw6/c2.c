// Составить функцию, возведение числа N в степень P.
// Два целых числа: N по модулю не превосходящих 1000 и P ≥ 0
#include <stdio.h>
int power(int n, int p) {
  int res = 1;
  while (p > 0) {
    res *= n;
    p--;
  }
  return res;
}

int main(void) {
  int n, p = 0;
  scanf("%d %d", &n, &p);
  printf("%d\n", power(n, p));
  return 0;
}