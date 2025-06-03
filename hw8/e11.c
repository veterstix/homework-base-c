// Считать массив из 10 элементов ...
// и отсортировать его по последней цифре.

#include <stdio.h>

#define ARR_SIZE 10

void print_arr(int arr[], int n) {
  for (int i = 0; i < n; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");
}

void insertion_sort(int arr[], int n) {
  for (int i = 0; i < ARR_SIZE; i++) {
    for (int j = i+1; j < ARR_SIZE; j++) {
      if (arr[i] > arr[j]) {
        int tmp = arr[i];
        arr[i] = arr[j];
        arr[j] = tmp;
      }
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

  for (i = 0; i < ARR_SIZE; i++) {
    for (int j = i+1; j < ARR_SIZE; j++) {
      if (arr[i]%10 > arr[j]%10) {
        int tmp = arr[i];
        arr[i] = arr[j];
        arr[j] = tmp;
      }
    }    
  }

  print_arr(arr, ARR_SIZE);
  
  return 0;
}