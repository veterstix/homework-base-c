// Определите наибольшее значение числа в этой последовательности.
#include <stdio.h>
#include <limits.h>

#define max(x, y) (x > y ? x : y)

int max_find(int m) {
  int in;
  scanf("%d", &in);
  
  if (in == 0) {
    return m;
  }

  return max_find(max(m, in));
}

int main(void) {
  printf("%d\n", max_find(INT_MIN));
  return 0;
}