// Считать массив из 10 элементов и ...
// найти в нем максимальный и минимальный элементы и их номера.

#include <stdio.h>

#define ARR_SIZE 10

int main(void) {
  int arr[ARR_SIZE] = {0};
  
  int i = 0;
  while (i < ARR_SIZE) {
    scanf("%d", arr+i);
    i++;
  }

  int min = arr[0], max = arr[0];
  int min_idx = 0, max_idx = 0;
  i = 0;
  while (i < ARR_SIZE) {
    if (min > *(arr+i)) {
      min = *(arr+i);
      min_idx = i; 
    }

    if (max < *(arr+i)) {
      max = *(arr+i);
      max_idx = i; 
    }

    i++;
  }

  printf("%d %d %d %d\n", max_idx+1, max, min_idx+1, min);
  return 0;
}