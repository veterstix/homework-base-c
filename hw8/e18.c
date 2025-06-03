// В диапазоне натуральных чисел от 2 до N определить, ...
// сколько из них кратны любому из чисел в диапазоне от 2 до 9.

#include <stdio.h>

#define ARR_SIZE 10

int main(void) {

  int n;
  scanf("%d", &n);
  int res[10] = {0};

  for (int i = 2; i <= n; i++) {
    for (int j = 2; j < 10; j++) {
      if (i%j == 0) {
        res[j]++;
      }
    }
  }

  for (int j = 2; j < 10; j++) {
    printf("%d %d\n", j, res[j]);
  }


  return 0;
}