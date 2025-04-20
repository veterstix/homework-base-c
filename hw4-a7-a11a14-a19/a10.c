#include <stdio.h>

int main(void) {
  #define SZ 5
  int arr[SZ];
  for (int i = 0; i < SZ; i++) {
    scanf("%d", arr+i);
  }
  
  int min = arr[0];
  for (int i = 1; i < SZ; i++) {
    if (arr[i] < min) {
      min = arr[i];
    }
  }
  printf("%d\n", min);
  return 0;
}