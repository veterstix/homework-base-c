// В файле input.txt дано предложение.
// Необходимо заменить все имена «Ling» на «Cao» и записать результат в файл output.txt.

// Ling, Ling, Ling and Ling!!!
// Cao, Cao, Cao and Cao!!!

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define SIZE_BUF 10001

#define INPUTFILE "input.txt"
#define OUTPUTFILE "output.txt"

#define WORD1STR "Ling"
#define WORD2STR "Cao"
#define LEN_WORD1STR strlen(WORD1STR)
#define LEN_WORD2STR strlen(WORD2STR)

int str_equal(char s1[], char s2[], int size) {
  for (int i = 0; i < size; i++) {
    if (s1[i] != s2[i]) {
      return 0;
    }
  }
  return 1;
}

int symbol_not_letter_not_digit(char ch) {
  if (ch >= 'a' && ch <= 'z') {
    return 0;
  }
  if (ch >= 'A' && ch <= 'Z') {
    return 0;
  }
  if (ch >= '0' && ch <= '9') {
    return 0;
  }

  return 1;
}

int main(void) {
  FILE *fd = NULL;
  char buf[SIZE_BUF] = {0};
  char ch;
  int i;

  // read
  fd = fopen(INPUTFILE, "r");
  if (!fd) {
    perror("Failed to open"INPUTFILE"file");
    exit(1);
  }

  i = 0;
  int count = 0;
  while ((fscanf(fd, "%c", &ch) == 1) && ch != EOF && ch != '\n') {
    buf[i] = ch;
    i++;
    if (i > SIZE_BUF) {
      perror("Input > size buffer");
      fclose(fd);
      exit(1);
    }
  }
  fclose(fd);

  // есть такой тест, когда на входе пустота
  // и чтобы его пройти, нужно обязательно открыть "output.txt" ...
  // и закрыть.
  // сделать #if 0
#if 1
  if (strlen(buf) == 0) {
    perror("Buffer empty");
    exit(1);
  }
#endif

  // logic
  int len_buf = i;
  char res[SIZE_BUF] = {0};
  int j = 0;

  for (i = 0; i < len_buf; i++) {
    if ((buf[i] == WORD1STR[0]) && (i + (LEN_WORD1STR-1) < len_buf) && str_equal(buf+i, WORD1STR, LEN_WORD1STR)) {
      for (int k = 0; k < strlen(WORD2STR); k++) {
        res[j] = WORD2STR[k];
        j++;
      }
      i += LEN_WORD1STR-1;
      continue; 
    }
    res[j] = buf[i];
    j++;
  }

  // write
  fd = NULL;
  fd = fopen(OUTPUTFILE, "w");
  if (!fd) {
    perror("Failed to open"OUTPUTFILE"file");
    exit(1);
  }

  fprintf(fd, "%s", res);
  
  fclose(fd);
  return 0;
}