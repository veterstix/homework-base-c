// Строчную в заглавную

#include <stdio.h>

char small2bigletter(char c) {
  if (c >= 'a' && c <= 'z') {
    return c - ('a' - 'A');
  }
  return c;
}

int main(void) {
  char ch = 0;
  int sum = 0;
  while (scanf("%c", &ch) && ch != '.') {
      printf("%c", small2bigletter(ch));
  }
  printf("\n");
  return 0;
}