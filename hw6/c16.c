// Простое ли число?

#include <stdio.h>
#include <math.h>

int is_prime(int n) {
  if (n == 0 || n == 1) { // 1 не простое и не составное
    return 0;
  }
  int i = 2;
  while (i <= sqrt(n)) {
    if (n%i == 0) {
      return 0;
    }
    i++;
  }
  return 1;
}

int main(void) {
  int num = 0;
  scanf("%d", &num);
  is_prime(num) ? printf("YES\n") : printf("NO\n");
  return 0;
}