// Считать 10 чисел в диапазоне от -500 до 500 и ...
// разложить по двум массивам: в одни помещать только положительные, ...
// во второй - только отрицательные. 
// Числа, равные нулю, игнорировать.
// Вывести на экран все элементы обоих массивов.
#include <stdio.h>

#define ARR_SIZE 10

void print_arr(int arr[], int n) {
  for (int i = 0; i < n; i++) {
    printf("%d ", arr[i]);
  }
}

int main(void) {

  int in[ARR_SIZE] = {0};
  
  int i = 0;
  while (i < ARR_SIZE) {
    scanf("%d", in+i);
    i++;
  }

  int out1[ARR_SIZE] = {0};
  int out2[ARR_SIZE] = {0};
  int j = 0;
  int k = 0;
  for (i = 0; i < ARR_SIZE; i++) {
    if (in[i] > 0) {
      out1[j] = in[i];
      j++;
    } else if (in[i] < 0) {
      out2[k] = in[i];
      k++;
    }
  }

  print_arr(out1, j);
  print_arr(out2, k); 
  return 0;
}