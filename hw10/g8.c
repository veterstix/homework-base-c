// В файле input.txt дана строка, не более 1000 символов, содержащая буквы, целые числа и иные символы.
// Требуется все числа, которые встречаются в строке, поместить в отдельный целочисленный массив.
// Например, если дана строка "data 48 call 9 read13 blank0a", то в массиве числа 48, 9, 13 и 0.
// Вывести массив по возрастанию в файл output.txt.

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define SIZE_BUF 1024

#define INPUTFILE "input.txt"
#define OUTPUTFILE "output.txt"

int is_num(char ch) {
  if (ch >= '0' && ch <= '9') {
    return 1;
  }
  return 0;
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
  // get num
  int len_buf = i;
  int num = 0;
  int nums[SIZE_BUF];
  int j = 0; // iterator for nums
  int pred = 0; // flag dlya pred elementa

  for (i = 0; i < len_buf; i++) {
    if (is_num(buf[i])) {
      num = (num * 10) + (int)(buf[i]-'0');
      pred = 1;
    } else { // drop
      if (pred) {
        nums[j] = num;
        j++;
      }
      pred = 0;
      num = 0;
    }
  }

  // esli v konce chislo
  // nujno proverit
  if (pred) {
    nums[j] = num;
    j++;
  }

  // sort
  int len_nums = j;
  for (i = 0; i < len_nums; i++) {
    for (j = i; j < len_nums; j++) {
      if (nums[i] > nums[j]) {
        int tmp = nums[i];
        nums[i] = nums[j];
        nums[j] = tmp;
      }
    }
  }

  // write
  fd = NULL;
  fd = fopen(OUTPUTFILE, "w");
  if (!fd) {
    perror("Failed to open"OUTPUTFILE"file");
    exit(1);
  }

  for (i = 0; i < len_nums; i++) {
    fprintf(fd, "%d ", nums[i]); 
  }

  fclose(fd);
  return 0;
}