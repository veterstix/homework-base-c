// Считать предложение из файла input.txt и определить можно ли из английских букв ...
// предложения записанного в файле получить одно слово - палиндром.
// Ответ напечатать на стандартный поток вывода.
// Требуется реализовать логическую функцию и применить ее.
// is_palindrom(string)

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define INPUTFILE "input.txt"
#define OUTPUTFILE "output.txt"

static int is_lowercase(char ch) {
  if (ch >= 'a' && ch <= 'z') {
    return 1;
  }
  return 0;
}

static int is_palindrom(char s[], int len) {
  int freq[52] = {0};

  int sum = 0;
  for (int i = 0; i < len; i++) {
    if (is_lowercase(s[i])) {
      freq[s[i]-'a']++; 
    } else {
      freq[s[i]-'a'+26]++;
    }
    sum++;
  }


  for (int i = 0; i < 52; i++) {
    int tmp = freq[i]/2;
    if (tmp) {
      sum -= (freq[i]/2)*2;
    }
  }

  // все парные разошлись и ...
  // если в сумме останется одна буква, то это нормально ...
  // это удовлетворяет условиям палиндрома
  return sum > 1;
}

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
    if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z')) {
      buf[i] = ch;
      i++;
    }
  }
  fclose(fd);

  if (strlen(buf) == 0) {
    perror("Buffer empty");
    exit(1);
  }

  int size_buf = i;
  printf("%s", is_palindrom(buf, size_buf) == 0 ? "YES" : "NO");
  
  return 0;
}
