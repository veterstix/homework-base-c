// Переставить цифры в числе так, ... 
// что бы получилось максимальное число.

#include <stdio.h>

int main(void) {
  int arr[10] = {0};
  
  int n = 0;
  scanf("%d", &n);

  while (n != 0) {
    arr[n%10]++;
    n/=10;
  }

  int ans = 0;
  int i = 9;
  while (i >= 0) {  
    while (arr[i] != 0) {
      ans = ans*10 + i;
      arr[i]--;
    }
    i--;
  }

  printf("%d\n", ans);
  return 0;
}