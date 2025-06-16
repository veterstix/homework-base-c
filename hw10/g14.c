// В файле input.txt в одной строке фамилию, имя и отчество.
// Сформировать файл приветствие output.txt, где останутся имя и фамилия

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define INPUTFILE "input.txt"
#define OUTPUTFILE "output.txt"

int main(void) {
  FILE *fd = NULL;

  // read
  fd = fopen(INPUTFILE, "r");
  if (!fd) {
    perror("Failed to open"INPUTFILE"file");
    exit(1);
  }

  char name[64] = {0};
  char surname[64] = {0};

  fscanf(fd, "%s %s %*s", surname, name);
  fclose(fd);

  // write
  fd = NULL;
  fd = fopen(OUTPUTFILE, "w");
  if (!fd) {
    perror("Failed to open"OUTPUTFILE"file");
    exit(1);
  }
  
  fprintf(fd, "Hello, %s %s!", name, surname);
  
  fclose(fd);
  return 0;
}