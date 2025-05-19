// Написать логическую рекурсивную функцию и ...
// используя ее определить является ли введенное натуральное число точной степенью двойки.


#include <stdio.h>


int is2pow(int n) {
  if (n <= 2) {
    return 1;
  }
  return ((n%2 == 0) ? 1 : 0) & is2pow(n/2);
}


int main(void) {
  int n = 0;
  scanf("%d", &n);
  if (n < 1) {
    printf("NO");
  } else {
    is2pow(n) == 1 ? printf("YES") : printf("NO");
  }
  return 0;
}