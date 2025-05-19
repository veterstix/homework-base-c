// Верно ли, что сумма его цифр – четное число?

#include <stdio.h>

int is_sum_num_even(int n) {
  int sum = 0;

  while (n > 0) {
    sum += n % 10;
    n /= 10;
  }

  return !(sum&1);
}

int main(void) {
  int num = 0;
  scanf("%d", &num);
  is_sum_num_even(num) ? printf("YES\n") : printf("NO\n");
  return 0;
}