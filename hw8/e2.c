// Ввести c клавиатуры массив из 5 элементов, ...
// найти минимальный из них.
#include <stdio.h>

#define ARR_SIZE 5

int main(void) {
  int arr[ARR_SIZE] = {0};
  
  int i = 0;
  while (i < ARR_SIZE) {
    scanf("%d", arr+i);
    i++;
  }

  int min = arr[0];
  i = 0;
  while (i < ARR_SIZE) {
    min = min > *(arr+i) ? *(arr+i) : min;  
    i++;
  }

  printf("%d\n", min);
  return 0;
}