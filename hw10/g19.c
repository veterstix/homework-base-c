// Разработать функцию дана строка из маленьких английских букв. 
// Составить из символов палиндром максимальной длинны.
// При составлении палиндрома буквы в палиндроме должны быть расположены в лексикографическом порядке.
// Записать ответ в файл output.txt.

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define SIZE_BUF 26
#define SIZE_RES_BUF 1024

#define INPUTFILE "input.txt"
#define OUTPUTFILE "output.txt"

int main(void) {
  FILE *fd = NULL;
  char freq[SIZE_BUF] = {0};
  char ch;

  // read
  fd = fopen(INPUTFILE, "r");
  if (!fd) {
    perror("Failed to open"INPUTFILE"file");
    exit(1);
  }

  // 1.
  int size_symbols = 0;
  while ((fscanf(fd, "%c", &ch) == 1) && ch != EOF && ch != '\n') {
    if (ch >= 'a' && ch <= 'z') {
      freq[ch-'a']++;
      size_symbols++;
    }
  }
  fclose(fd);

  // logic
  char res[SIZE_RES_BUF] = {0};
  int j = 0;
  
  // 2.
  for (int i = 0; i < SIZE_BUF; i++) {
    int tmp = freq[i]/2;
    if (tmp) {
      while (tmp != 0) {
        if (j < SIZE_RES_BUF) res[j] = i+'a';
        j++;
        tmp--;
      }
      size_symbols -= (freq[i]/2)*2;
      freq[i] -= (freq[i]/2)*2;
    }
  }

  int save_j = j-1;

  // 3.
  if (size_symbols) {
    for (int i = 0; i < SIZE_BUF; i++) {
      if (freq[i] != 0) {
        if (j < SIZE_RES_BUF) res[j] = i+'a';
        j++;
        break;
      }
    }
  }

  // 4.
  for (int i = save_j; i >= 0; i--) {
    if (j < SIZE_RES_BUF) res[j] = res[i];
    j++;
  }

  // write
  fd = NULL;
  fd = fopen(OUTPUTFILE, "w");
  if (!fd) {
    perror("Failed to open"OUTPUTFILE"file");
    exit(1);
  }

  for (int i = 0; i < j; i++) {
    fprintf(fd, "%c", res[i]);
  }


  fclose(fd);
  return 0;
}

// 1. Составим массив частот.
// 2. Сразу в ответ запишем половину от частоты каждой буквы, а другую будем держать в уме.
// 3. Проверим, не осталось ли в массиве частот - буквы, если осталось, то добавим.
// 4. Добавляем другую половину, которую держали в уме, только в обратном порядке.
// |--------------------|
// | freq | res         |
// | -------------------|
// | 1.   |             |
// | abcz | 0           |
// | ab z |             |
// | a  z |             |
// | a  z |             |
// | a    |             |
// | ---- |             |
// | 5214 |             |
// | 2.   |             |
// | abcz | aabzz       |
// | ---- |             |
// | 1010 |             |
// | 3.   |             |
// | abcz | aabzza      |
// | ---- |             |
// | 0010 |             |
// | 4.   |             |
// |      | aabzzazzbaa |
// |--------------------|