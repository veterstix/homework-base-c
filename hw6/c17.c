// В заданном числе сумма цифр равна произведению?

#include <stdio.h>

int is_happy_number(int n) {
  int sum = 0;
  int prod = 1;

  while (n > 0) {
    sum += n % 10;
    prod *= n % 10;
    n /= 10;
  }

  return sum == prod;
}

int main(void) {
  int num = 0;
  scanf("%d", &num);
  is_happy_number(num) ? printf("YES\n") : printf("NO\n");
  return 0;
}