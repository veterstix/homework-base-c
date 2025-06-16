#include <stdio.h>

void swap_negmax_last(int size, int a[]) {
  int max = -1000000;
  int max_idx = -1;

  for (int i = 0; i < size; i++) {
    if (a[i] < 0 && max < a[i]) {
      max = a[i];
      max_idx = i;
    }
  }

  if (max_idx != -1) {
    int tmp = a[size-1];
    a[size-1] = max;
    a[max_idx] = tmp;
  }
}

int main() {
  int arr[] = {50,90,51,90,54,50,18,84,16,3};
  swap_negmax_last(10, arr);

  for (int i = 0; i < 10; i++) {
    printf("%d\t", arr[i]);
  }
  return 0;
}