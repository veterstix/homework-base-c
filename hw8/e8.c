// Считать массив из 12 элементов ... 
// и выполнить инверсию для каждой трети массива.

#include <stdio.h>

#define ARR_SIZE 12

static void read_array(int arr[], int sz) {
  int i = 0;
  while (i < sz) {
    scanf("%d", arr+i);
    i++;
  }
}

static void rotate_array(int arr[], int l, int r) {
  while (l <= r) {
    int tmp = arr[l]; 
    arr[l] = arr[r];
    arr[r] = tmp;
    l++;
    r--;
  }
}

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
  
  read_array(arr, ARR_SIZE);

  int i = 0;
  while (i < ARR_SIZE) {
    rotate_array(arr, i, i+ARR_SIZE/3-1); 
    i += ARR_SIZE/3;
  }
  print_array(arr, ARR_SIZE);

  return 0;
}