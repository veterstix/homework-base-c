#include <stdio.h>

#define ARR_SIZE 10

int main(void) {

  int in[ARR_SIZE] = {0};
  
  int i = 0;
  while (i < ARR_SIZE) {
    scanf("%d", in+i);
    i++;
  }

  int amount_odd = 0;
  int amount_even = 0;

  for (i = 0; i < ARR_SIZE; i++) {
    if (in[i]&1) {
      amount_odd++;
    } else {
      amount_even++;
    }
  }

  if (amount_even > amount_odd) {
    for (i = 0; i < ARR_SIZE; i++) {
      if (in[i]&1) {
        int tmp = in[i];
        int prod = 1;
        while (tmp != 0) {
          if ((tmp%10)&1) {
            prod *= tmp%10;
          }
          tmp/=10;
        }

        in[i] = prod;
      }
    }
  } else {
    for (i = 0; i < ARR_SIZE; i++) {
      if ((in[i]&1) == 0) {
        int tmp = in[i];
        int prod = 1;
        while (tmp != 0) {
          if (((tmp%10)&1) == 0) {
            prod *= tmp%10;
          }
          tmp/=10;
        }

        in[i] = prod;
      }
    }
  }

  for (i = 0; i < ARR_SIZE; i++) {
    printf("%d ", in[i]);
  }
  
  return 0;
}