// Считать массив из 10 элементов ...
// и посчитать сумму положительных элементов массива.

#include <stdio.h>

#define ARR_SIZE 10

int main(void) {
  int arr[ARR_SIZE] = {0};
  
  int i = 0;
  while (i < ARR_SIZE) {
    scanf("%d", arr+i);
    i++;
  }

  int ans = 0;
  i = 0;
  while (i < ARR_SIZE) {
    if (*(arr+i) > 0) {
      ans += *(arr+i);
    }
    i++;
  }

  printf("%d\n", ans);
  return 0;
}