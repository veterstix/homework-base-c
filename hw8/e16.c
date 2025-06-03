// Дан массив из 10 элементов. 
// Определить, какое число в массиве встречается чаще всего.
// Гарантируется, что такое число ровно 1.

#include <stdio.h>

#define ARR_SIZE 10

int main(void) {

  int in[ARR_SIZE] = {0};
  
  int i = 0;
  while (i < ARR_SIZE) {
    scanf("%d", in+i);
    i++;
  }

  int val = 0;
  int freq = 0;

  for (i = 0; i < ARR_SIZE; i++) {
    int curr_freq = 0;
    for (int j = i+1; j < ARR_SIZE; j++) {
      if (in[i] == in[j]) {
        curr_freq++;

        if (curr_freq > freq) {
          freq = curr_freq;
          val = in[i];
        }
      }
    } 
  }

  printf("%d\n", val);
  
  return 0;
}