// В файле input.txt считать символьную строку, не более 10 000 символов.
// Посчитать количество строчных (маленьких) и прописных (больших) букв в введенной строке. 
// Учитывать только английские буквы. Результат записать в файл output.txt.

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
  int small = 0, big = 0;
  int size_buf = i;
  for (i = 0; i < size_buf; i++) {

    if (buf[i] >= 'a' && buf[i] <= 'z') {
      small++;
    } else if (buf[i] >= 'A' && buf[i] <= 'Z') {
      big++;
    } else {
      continue;
    }
  }

  // write
  fd = NULL;
  fd = fopen(OUTPUTFILE, "w");
  if (!fd) {
    perror("Failed to open"OUTPUTFILE"file");
    exit(1);
  }
  fprintf(fd, "%d %d", small, big);
  fclose(fd);
  return 0;
}