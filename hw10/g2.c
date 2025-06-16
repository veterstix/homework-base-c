// Считать число N из файла input.txt.
// Сформировать строку из N символов. N четное число, не превосходящее 26.
// На четных позициях должны находится четные цифры в порядке возрастания, ...
// кроме 0, на нечетных позициях - заглавные буквы в порядке следования в английском алфавите.
// Результат записать в файл output.txt

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define INPUTFILE "input.txt"
#define OUTPUTFILE "output.txt"

int main(void) {
  FILE *fd = NULL;
  int n;

  // read
  fd = fopen(INPUTFILE, "r");
  if (!fd) {
    perror("Failed to open"INPUTFILE"file");
    exit(1);
  }
  fscanf(fd, "%d", &n);
  fclose(fd);

  // write
  fd = NULL;
  fd = fopen(OUTPUTFILE, "w");
  if (!fd) {
    perror("Failed to open"OUTPUTFILE"file");
    exit(1);
  }
  char ch = 'A';
  int num = 2;
  while (n > 0) {
    if (num > 8) {
      num = 2;
    }
    if (ch > 'Z') {
      ch = 'A';
    }
    fprintf(fd, "%c%d", ch, num);
    ch++;
    num+=2;
    n-=2;
  }
  fclose(fd);
  return 0;
}