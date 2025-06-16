// В файле input.txt дана строка слов, разделенных пробелами.
// Найти самое длинное слово и вывести его в файл output.txt.
// Случай, когда самых длинных слов может быть несколько, не обрабатывать.

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
  int len_curr_word = 0;
  int max_len_curr_word = 0;
  int max_idx = -1;
  while ((fscanf(fd, "%c", &ch) == 1) && ch != EOF && ch != '\n') {
    if ((ch == ' ')) {
      if (len_curr_word > max_len_curr_word) {
        max_len_curr_word = len_curr_word;
        max_idx = i;
      }
      len_curr_word = 0;
    } else {
      len_curr_word++;
    }

    buf[i] = ch;
    i++;
  }
  fclose(fd);

  if (strlen(buf) == 0) {
    perror("Buffer empty");
    exit(1);
  }

  // если нет пробелов строке и буффер не пуст
  if (max_idx == -1) {
    max_idx = i;
    max_len_curr_word = i;
  }

  // write
  fd = NULL;
  fd = fopen(OUTPUTFILE, "w");
  if (!fd) {
    perror("Failed to open"OUTPUTFILE"file");
    exit(1);
  }
  for (i = max_idx - max_len_curr_word; i < max_idx; i++) {
    fprintf(fd, "%c", buf[i]);
  }
  fclose(fd);
  return 0;
}