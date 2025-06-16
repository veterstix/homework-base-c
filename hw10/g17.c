// В файле input.txt записаны символы. Необходимо разработать функцию, 
// которая меняет местами пары соседних символов не обращая внимание на символы пробел.
// Если количество символов нечетно (пробелы не считаем), то последний символ не меняем.
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
  // logic
  int len_buf = i;
  int l = 0;
  int r = l+1;
 
  while (r < len_buf) {
    if (buf[l] == ' ') {
      l++;
      continue;
    }
    if (buf[r] == ' ') {
      r++;
      continue;
    }

    if (l == r) {
      r++;
      continue;
    }

    int tmp = buf[l];
    buf[l] = buf[r];
    buf[r] = tmp;

    l = r+1;
    r = l+1;
    
  }

  // write
  fd = NULL;
  fd = fopen(OUTPUTFILE, "w");
  if (!fd) {
    perror("Failed to open"OUTPUTFILE"file");
    exit(1);
  }

  for (i = 0; i < len_buf; i++) {
    fprintf(fd, "%c", buf[i]); 
  }

  fclose(fd);
  return 0;
}