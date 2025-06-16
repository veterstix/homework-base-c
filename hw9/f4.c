// Написать только одну функцию. 
// Всю программу отправлять не надо. 
// Вывести в порядке возрастания цифры, входящие в строку. 
// Цифра - количество.
// Функция должно строго соответствовать прототипу:
// void print_digit(char s[])
#include <stdio.h>
#include <string.h>

void print_digit(char s[]) {
  #define ARR_SIZE 10

  int freq[ARR_SIZE] = {0};
  int i = 0;
  while (s[i] != '.') {
    if (s[i] >= '0' && s[i] <= '9') {
      freq[s[i]-'0']++; 
    }
    i++;
  }

  for (int i = 0; i < ARR_SIZE; i++) {
    if (freq[i] != 0) {
      printf("%d %d\n", i, freq[i]); 
    }
  }
}

int main(void) {
  char buf[4096] = {0};

  int i = 0;
  char ch;
  while (scanf("%c", &ch) && ch != '.') {
    if (ch == ' ') {
      continue;
    }
    buf[i] = ch;
    i++;
  }

  print_digit(buf);

  return 0;
}