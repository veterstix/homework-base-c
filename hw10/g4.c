// В файле input.txt даны два слова не более 100 символов каждое, разделенные одним пробелом.
// Найдите только те символы слов, которые встречаются в обоих словах только один раз. 
// Напечатайте их через пробел в файл output.txt в лексикографическом порядке.

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

  int freq1[26] = {0};
  int freq2[26] = {0};
  int *ptr = freq1;
  while ((fscanf(fd, "%c", &ch) == 1) && ch != EOF && ch != '\n') {
    if (ch == ' ') {
      ptr = freq2;
      continue;
    }
    ptr[ch-'a']++;
  }
  fclose(fd);

  // write
  fd = NULL;
  fd = fopen(OUTPUTFILE, "w");
  if (!fd) {
    perror("Failed to open"OUTPUTFILE"file");
    exit(1);
  }

  for (int i = 0; i < 26; i++) {
    if (freq1[i] == 1 && freq2[i] == 1) {
      fprintf(fd, "%c ", i+'a');
    }
  }

  fclose(fd);
  return 0;
}