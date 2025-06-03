// Считать массив из 10 элементов и ...
// отобрать в другой массив все числа, ...
// у которых вторая с конца цифра (число десятков) – ноль.

#include <stdio.h>
#include <stdlib.h>

#define ARR_SIZE 10

void print_arr(int arr[], int n) {
  for (int i = 0; i < n; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");
}

int main(void) {

  int arr[ARR_SIZE] = {0};
  
  int i = 0;
  while (i < ARR_SIZE) {
    scanf("%d", arr+i);
    i++;
  }

  int *ans = (int*)malloc(ARR_SIZE * sizeof(int));
  int j = 0;
  for (i = 0; i < ARR_SIZE; i++) {
    if (arr[i]/10%10 == 0) {
      ans[j] =  arr[i];
      j++;
    }
  }

  print_arr(ans, j);

  free(ans);  
  return 0;
}