// Ввести c клавиатуры массив из 5 элементов, ....
// найти среднее арифметическое всех элементов массива.

#include <stdio.h>

#define ARR_SIZE 5

int main(void) {
  int arr[ARR_SIZE] = {0};
  
  int i = 0;
  while (i < ARR_SIZE) {
    scanf("%d", arr+i);
    i++;
  }

  double ans = 0.0;
  i = 0;
  while (i < ARR_SIZE) {
    ans += *(arr+i); 
    i++;
  }

  printf("%.3f\n", ans/ARR_SIZE);
  return 0;
}