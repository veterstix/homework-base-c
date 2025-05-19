// Сумма цифр в строке

#include <stdio.h>

int digit_to_num(char c) {
  if (c >= '0' && c <= '9') {
    return c - '0';
  }
  return 0;
}

int main(void) {
  char ch = 0;
  int sum = 0;
  while (scanf("%c", &ch) && ch != '.') {
      sum += digit_to_num(ch);
  }

  printf("%d\n", sum);
  return 0;
}