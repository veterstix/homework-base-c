// В файле input.txt записан полный адрес файла (возможно, без расширения).
// Необходимо изменить его расширение на ".html" и записать результат в файл output.txt.

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
  int count = 0;
  while ((fscanf(fd, "%c", &ch) == 1) && ch != EOF && ch != '\n') {
    buf[i] = ch;
    i++;
  }
  fclose(fd);

  if (strlen(buf) == 0) {
    perror("Buffer empty");
    exit(1);
  }

  int flag = 0;
  int size_buf = i;
  for (i = size_buf-1; i >= 0; --i) {
    if (buf[i] == '.') {
      break;
    }
    if (buf[i] == '/') {
      flag = 1;
      break;
    }
  }

  if (flag || (i == -1)) {
    i = size_buf;
  }
  --i;
  buf[++i] = '.';
  buf[++i] = 'h';
  buf[++i] = 't';
  buf[++i] = 'm';
  buf[++i] = 'l';
  buf[++i] = '\0';

  // write
  fd = NULL;
  fd = fopen(OUTPUTFILE, "w");
  if (!fd) {
    perror("Failed to open"OUTPUTFILE"file");
    exit(1);
  }
  size_buf = i;
  for (i = 0; i < size_buf; i++) {
    fprintf(fd, "%c", buf[i]);
  }
  
  fclose(fd);
  return 0;
}