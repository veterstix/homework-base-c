// Дан массив из 10 элементов. 
// В массиве найти элементы, ...
// которые в нем встречаются только один раз, ...
// и вывести их на экран.

#include <stdio.h>

#define ARR_SIZE 10

int main(void) {

  int in[ARR_SIZE] = {0};
  
  int i = 0;
  while (i < ARR_SIZE) {
    scanf("%d", in+i);
    i++;
  }

  for (i = 0; i < ARR_SIZE; i++) {
    int flag = 1;
    for (int j = 0; j < ARR_SIZE; j++) {
      if (in[i] == in[j] && i != j) {
        flag = 0;
        break;
      }
    }

    if (flag) {
      printf("%d ", in[i]); 
    }
  }

  return 0;
}