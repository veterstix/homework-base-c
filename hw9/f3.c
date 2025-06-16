// Написать функцию и программу демонстрирующую работу данной функции.
// Вывести в порядке возрастания цифры, ... 
// входящие в десятичную запись натурального числа N, не более 1000 цифр.
// Цифра пробел сколько раз данная цифра встречается в числе.
#include <stdio.h>
#include <string.h>

#define ARR_SIZE 10

int main(void) {

  int freq[ARR_SIZE] = {0};
  char buf[1001] = {0};

  scanf("%s", buf);

  for (int i = 0; i < strlen(buf); i++) {
    freq[buf[i]-'0']++; 
  }

  for (int i = 0; i < ARR_SIZE; i++) {
    if (freq[i] != 0) {
      printf("%d %d\n", i, freq[i]); 
    }
  }

  return 0;
}