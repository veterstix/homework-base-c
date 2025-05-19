// Верно ли, что в заданном числе все цифры стоят по возрастанию?

#include <stdio.h>

int is_grow_up(int n) {
  int pred = 10;

  while (n > 0) {
    if ((n % 10) < pred) {
      pred = n % 10;
    } else {
      return 0;
    }
    n /= 10;
  }

  return 1;
}

int main(void) {
  int num = 0;
  scanf("%d", &num);
  is_grow_up(num) ? printf("YES\n") : printf("NO\n");
  return 0;
}