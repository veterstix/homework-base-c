// Считать массив из 10 элементов ... 
// и выполнить инверсию отдельно для 1-ой и 2-ой половин массива. 
// Необходимо изменить считанный массив и напечатать его одним циклом.

#include <stdio.h>

#define ARR_SIZE 10

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
  rotate_array(arr, 0, ARR_SIZE/2 - 1);
  rotate_array(arr, ARR_SIZE/2, ARR_SIZE-1);
  print_array(arr, ARR_SIZE);

  return 0;
}