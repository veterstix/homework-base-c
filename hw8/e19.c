// Вывести в порядке следования цифры, 
// входящие в десятичную запись натурального числа N.

#include <stdio.h>
#include <math.h>

int main(void) {
  int n = 0;
  scanf("%d", &n);

  int count_digit = 0;
  int tmp = n;
  while (tmp != 0) {
    count_digit++;
    tmp/=10;
  }
  count_digit--;
  while (count_digit >= 0) {
    printf("%d ", (int)(n / pow(10, count_digit)));
    n %= (int)pow(10, count_digit);
    count_digit--;
  }

  return 0;
}