// Считать массив из 10 элементов и ...
// выделить в другой массив все числа, ... 
// которые встречаются более одного раза. 
// В результирующем массиве эти числа не должны повторяться.

#include <stdio.h>

#define ARR_SIZE 10

int main(void) {

  int in[ARR_SIZE] = {0};
  
  int i = 0;
  while (i < ARR_SIZE) {
    scanf("%d", in+i);
    i++;
  }

  int res[ARR_SIZE] = {0};
  int n = 0;

  for (i = 0; i < ARR_SIZE; i++) {
    for (int j = i+1; j < ARR_SIZE; j++) {
      if (in[i] == in[j] && i != j) {
        int flag = 1;
        for (int k = 0; k < n; k++) {
          if (in[i] == res[k]) {
            flag = 0;
          }
        }

        if (flag) {
          res[n] = in[i];
          n++;
        }
      }
    }
  }

  for (i = 0; i < n; i++) {
    printf("%d ", res[i]);
  }

  return 0;
}