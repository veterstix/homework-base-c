#include <stdio.h>
#include <string.h>

static void print_array(char arr[], int sz) {
  int i = 0;
  while (i < sz) {
    printf("%c ", arr[i]);
    i++;
  }
  printf("\n");
}

void rle(char buf[], int size) {
  int i = 0;

  while(i < size) {
    char fix = buf[i];
    int count = 0;

    while (i < size && fix == buf[i]) {
      count++;
      i++;
    }
    if (count) {
      printf("%c%d", fix, count);
    }

  }
}

int main() {
  char buf[1001] = {0};
  
  char ch;
  int i = 0;
  while (scanf("%c", &ch) && ch != '.') {
    buf[i] = ch;
    i++;
  }

  rle(buf, strlen(buf));

  return 0;
}