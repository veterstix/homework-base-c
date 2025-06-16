// В файле input.txt дана строка из не более 1000 символов. 
// Показать номера символов, совпадающих с последним символом строки.
// Результат записать в файл output.txt

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
  ch = buf[i-1];
  int size_buf = i;
  for (i = 0; i < size_buf; i++) {
    if (i == size_buf-1) {
      continue;
    }
    if (ch == buf[i]) {
      fprintf(fd, "%d ", i);
    }
  }
  fclose(fd);
  return 0;
}