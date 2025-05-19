// Проверка на простоту

#include <stdio.h>
#include <math.h>

int is_prime(int n, int delitel) {
  if (delitel > sqrt(n)) {
    return 1;
  } 
  return (n%delitel != 0 ? 1 : 0) & is_prime(n, delitel+1);
}

int main(void) {
  int n = 0;
  scanf("%d", &n);
  if (n < 2) {
    printf("NO");
  } else {
    is_prime(n, 2) ? printf("YES") : printf("NO");
  }
  return 0;
}