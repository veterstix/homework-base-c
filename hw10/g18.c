// В файле input.txt необходимо удалить все лишние пробелы (в начале предложения и сдвоенные пробелы).
// Для решения задачи разработать функцию. Результат записать в output.txt.

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define SIZE_BUF 10001

#define INPUTFILE "input.txt"
#define OUTPUTFILE "output.txt"

int main(void) {
  FILE *fd = NULL;
  char buf[SIZE_BUF] = {0};
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
    if (i > SIZE_BUF) {
      perror("Input > size buffer");
      fclose(fd);
      exit(1);
    }
  }
  fclose(fd);

#if 1
  if (strlen(buf) == 0) {
    perror("Buffer empty");
    exit(1);
  }
#endif

  // logic
  // удалили с конца пробелы
  int len_buf = i;
  --i;
  while (i >= 0 && buf[i] == ' ') {
    --i;
  }
  len_buf = ++i;

  // удалили с начала пробелы
  i = 0;
  while (i < len_buf && buf[i] == ' ') {
    i++;
  }

  int save_i = i;

  char res[SIZE_BUF] = {0};
  int j = 0;
  char pred = 1;
  // удалили из серединки
  for (i; i < len_buf; i++) {
    if (buf[i] == ' ' && pred == ' ') {
      continue;
    }

    if (buf[i] == ' ') {
      pred = ' ';
    } else {
      pred = buf[i];
    }

    res[j] = buf[i];
    j++;
  }



  // write
  fd = NULL;
  fd = fopen(OUTPUTFILE, "w");
  if (!fd) {
    perror("Failed to open"OUTPUTFILE"file");
    exit(1);
  }

  // for (i = save_i; i < len_buf; i++) {
  //   fprintf(fd, "%c", buf[i]);
  // }

  for (i = 0; i < j; i++) {
    fprintf(fd, "%c", res[i]);
  }
  
  fclose(fd);
  return 0;
}