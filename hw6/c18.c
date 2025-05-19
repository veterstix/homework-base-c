// Количество цифр в строке

#include <stdio.h>

int is_digit(char c) {
  return c >= '0' && c <= '9';
}

int main(void) {
  char ch = 0;
  int count_digit = 0;
  while (scanf("%c", &ch) && ch != '.') {
    if (is_digit(ch)) {
      count_digit++;
    }
  }

  printf("%d\n", count_digit);
  return 0;
}