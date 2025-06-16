// В файле input.txt символьная строка не более 1000 символов.
// Необходимо проверить, является ли она палиндромом (палиндром читается одинаково в обоих направлениях).
// Реализовать логическую функцию is_palindrom(str) и записать ответ в файл output.txt.

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define INPUTFILE "input.txt"
#define OUTPUTFILE "output.txt"

int main(void) {
  FILE *fd = NULL;
  char buf[1024] = {0};
  char ch;
  int i;

  // read
  fd = fopen(INPUTFILE, "r");
  if (!fd) {
    perror("Failed to open"INPUTFILE"file");
    exit(1);
  }

  i = 0;
  while ((fscanf(fd, "%c", &ch) == 1) && ch != EOF && ch != '\n') {
    buf[i] = ch;
    i++;
  }
  fclose(fd);

  if (strlen(buf) == 0) {
    perror("Buffer empty");
    exit(1);
  }

  // logic
  char res[4] = {'Y', 'E', 'S', '\0'};
  int l = 0, r = --i;

  while (l <= r) {
    if (buf[l] != buf[r]) {
      sprintf(res, "%s", "NO");
      break;
    }
    l++;
    r--;
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