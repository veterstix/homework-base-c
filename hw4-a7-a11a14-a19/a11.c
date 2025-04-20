#include <stdio.h>

int main(void) {
  #define SZ 5
  int arr[SZ];
  for (int i = 0; i < SZ; i++) {
    scanf("%d", arr+i);
  }
  
  int max = arr[0];
  int min = arr[0];
  for (int i = 1; i < SZ; i++) {
    if (arr[i] > max) {
      max = arr[i];
    }
    if (arr[i] < min) {
      min = arr[i];
    }
  }
  printf("%d\n", max+min);
  return 0;
}