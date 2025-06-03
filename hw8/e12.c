// Считать массив из 10 элементов и ... 
// отсортировать первую половину по возрастанию, ...
// а вторую – по убыванию.

#include <stdio.h>

#define ARR_SIZE 10

void print_arr(int arr[], int n) {
  for (int i = 0; i < n; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");
}

void swap_decreasing(int *a, int *b) {
  if (*a < *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
  }
}

void swap_increasing(int *a, int *b) {
  if (*a > *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
  }
}

void sort_insertion(int arr[], int start, int end, void(*condition_swap)(int*, int*)) {
  for (int i = start; i < end; i++) {
    for (int j = i+1; j < end; j++) {
      condition_swap(arr+i, arr+j);
    }    
  }
}

int main(void) {

  int arr[ARR_SIZE] = {0};
  
  int i = 0;
  while (i < ARR_SIZE) {
    scanf("%d", arr+i);
    i++;
  }

  sort_insertion(arr, 0, ARR_SIZE/2, swap_increasing);
  sort_insertion(arr, ARR_SIZE/2, ARR_SIZE, swap_decreasing);

  print_arr(arr, ARR_SIZE);
  
  return 0;
}