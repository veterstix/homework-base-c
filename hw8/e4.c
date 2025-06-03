// Считать массив из 10 элементов и ... 
// найти в нем два максимальных элемента ... 
// и напечатать их сумму.

#include <stdio.h>

#define ARR_SIZE 10

int main(void) {
  int arr[ARR_SIZE] = {0};
  
  int i = 0;
  while (i < ARR_SIZE) {
    scanf("%d", arr+i);
    i++;
  }

  int max1_idx = 0, max2_idx = 1;
  i = 0;
  while (i < ARR_SIZE) {
    if (*(arr+max1_idx) < *(arr+i)) {
      max2_idx = max1_idx;
      max1_idx= i; 
    } else if (i > max2_idx && *(arr+max2_idx) < *(arr+i)) {
      max2_idx = i;
    }
    i++;
  }

  printf("%d\n", arr[max1_idx]+arr[max2_idx]);
  return 0;
}