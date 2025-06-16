// Cia очень любит равносторонние треугольники.
// Он все время выкладывает их из камней.
// Ling дал Cia камни и попросил его составить такой треугольник если это возможно.
// Помогите Cia сложить треугольник используя все камни или напечатайте слов NO, если это невозможно.
// Пример треугольников, которые составляет Cia:
//    *
//   * *
//  * * *
// * * * *

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define INPUTFILE "input.txt"
#define OUTPUTFILE "output.txt"

int main(void) {
  FILE *fd = NULL;
  char ch;

  // read
  fd = fopen(INPUTFILE, "r");
  if (!fd) {
    perror("Failed to open"INPUTFILE"file");
    exit(1);
  }

  int stars = 0;

  while ((fscanf(fd, "%c", &ch) == 1) && ch != EOF) {
    if (ch == '*') {
      stars++;
    }
  }
  fclose(fd);

  // write
  fd = NULL;
  fd = fopen(OUTPUTFILE, "w");
  if (!fd) {
    perror("Failed to open"OUTPUTFILE"file");
    exit(1);
  }

  // if amount stars == 0
  if (stars == 0) {
    fprintf(fd, "%s", "NO");
    goto end;
  }

  // check is possible this or not
  int i = 0;
  while (stars > 0) {
    i++;
    stars -= i;
  }

  if (stars != 0) {
    fprintf(fd, "%s", "NO");
    goto end;
  }

  // draw
  int strs = i;
  int space = strs;
  for (i = 1; i <= strs; i++) {
    for (int j = 0; j < space-i; j++) {
      fprintf(fd, "%c", ' ');
    }
    for (int j = 0; j < i; j++) {
      fprintf(fd, "%c%c", '*', ' ');
    }
    fprintf(fd, "%c", '\n');
  }

end:
  fclose(fd);
  return 0;
}