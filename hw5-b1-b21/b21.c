#include <stdio.h>

int main(void) {
  char ch;
  while (scanf("%c", &ch) && ch != '.') {
    if (ch >= 'A' && ch <= 'Z') {
      printf("%c", ch + 'a' - 'A');
    } else {
      printf("%c", ch);
    }
  }
  return 0;
}