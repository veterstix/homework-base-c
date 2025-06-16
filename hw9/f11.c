#include <stdio.h>

#define ARR_SIZE 30

int main(void) {

  int arr[ARR_SIZE] = {0};
  
  int i = 0;
  while (i < ARR_SIZE) {
    scanf("%d", arr+i);
    i++;
  }

  int idx1 = 0;
  int idx2 = 1;
  int mn_sum = arr[0] + arr[1];

  for (int i = 0; i < ARR_SIZE; i++) {
    for (int j = i+1; j < ARR_SIZE; j++) {
      if (arr[i]+arr[j] < mn_sum) {
        mn_sum = arr[i]+arr[j];
        idx1 = i;
        idx2 = j;
      }
    }
  }
  printf("%d %d\n", idx1, idx2);
  return 0;
}