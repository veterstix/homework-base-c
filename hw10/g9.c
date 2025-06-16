// В файле input.txt строка из меленьких и больших английских букв, знаков препинания и пробелов.
// Требуется удалить из нее повторяющиеся символы и все пробелы.
// Результат записать в файл output.txt.

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

  // write
  fd = NULL;
  fd = fopen(OUTPUTFILE, "w");
  if (!fd) {
    perror("Failed to open"OUTPUTFILE"file");
    exit(1);
  }
  int freq[52] = {0};
  int size_buf = i;
  for (i = 0; i < size_buf; i++) {
    if (buf[i] == ' ') {
      continue;
    }

    if ((buf[i] >= 'a' && buf[i] <= 'z') && freq[buf[i]-'a'] != 0) {
      continue;
    }

    if ((buf[i] >= 'A' && buf[i] <= 'Z') && freq[buf[i]-'A'+26] > 0) {
      continue;
    }

    if ((buf[i] >= 'A' && buf[i] <= 'Z')) {
      freq[buf[i]-'A'+26]++;
    }

    if ((buf[i] >= 'a' && buf[i] <= 'z')) {
      freq[buf[i]-'a']++;
    }
    fprintf(fd, "%c", buf[i]);
  }
  fclose(fd);
  return 0;
}