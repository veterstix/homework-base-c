// В файле input.txt дано предложение. 
// Необходимо определить, сколько слов заканчиваются на букву 'а'.
// Ответ записать в файл output.txt.

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
    if ((i != 0) && (ch == ' ') && (buf[i-1] == 'a')) { 
      count++;
    }
    buf[i] = ch;
    i++;
  }
  fclose(fd);

  if (strlen(buf) == 0) {
    perror("Buffer empty");
    exit(1);
  }

  // а если пробелов нету
  // а ещё так выходит что мы последнюю букву не проверяем, ...
  // так сказать краевые случаи
  if ((i-1 >= 0) && (buf[i-1] == 'a')) {
    count++;
  }

  // write
  fd = NULL;
  fd = fopen(OUTPUTFILE, "w");
  if (!fd) {
    perror("Failed to open"OUTPUTFILE"file");
    exit(1);
  }
  fprintf(fd, "%d", count);
  fclose(fd);
  return 0;
}