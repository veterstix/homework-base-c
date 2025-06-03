// Считать массив из 12 элементов ...
// и выполнить циклический сдвиг ВПРАВО на 4 элемента.
#include <stdio.h>

#define ARR_SIZE 12
#define SHIFT 4

static void print_array(int arr[], int sz) {
  int i = 0;
  while (i < sz) {
    printf("%d ", arr[i]);
    i++;
  }
  printf("\n");
}

int main(void) {
  int arr[ARR_SIZE] = {0};
  
  int i = 0;
  while (i < ARR_SIZE) {
    int idx = (i + SHIFT)%ARR_SIZE;
    scanf("%d", arr+idx);
    i++;
  }

  print_array(arr, ARR_SIZE);
  return 0;
}