// Математик Сисса бен Дахир
#include <stdio.h>
#include <stdint.h>

uint64_t ans(int a) {
  // return 1<<a; // ошибка, считает 1 типом int32
  return (uint64_t)1<<a;
}

int main(void) {
  int a = 0;
  scanf("%d", &a);
  printf("%lu\n", ans(a-1));
  return 0;
}