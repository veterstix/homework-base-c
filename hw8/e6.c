// Считать массив из 12 элементов ... 
// и посчитать среднее арифметическое элементов массива

#include <stdio.h>

#define ARR_SIZE 12

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

  printf("%.2f\n", ans/ARR_SIZE);
  return 0;
}