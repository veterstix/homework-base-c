// Дана строка заканчивающаяся символом точка '.' Напечатать строку наоборот.
// Реализуйте рекурсивную функцию, которая считывает и печатает строку наоборот.

#include <stdio.h>

void reverse_string() {
  char ch;
  scanf("%c", &ch);

  if (ch != '.') {
    reverse_string();
    printf("%c", ch);
  }
}

int main(void) {
  reverse_string();
  return 0;
}