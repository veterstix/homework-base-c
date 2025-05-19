// Дана монотонная последовательность, 
// в которой каждое натуральное число k встречается ровно k раз: 1, 2, 2, 3, 3, 3, 4, 4, 4, 4,…
// Выведите первые n членов этой последовательности.

#include <stdio.h>

void rec(int k, int n) {
  if (n < 0) {
    return;
  }
  for (int i = 0; i < n && i < k; i++) {
    printf("%d ", k);
  }
  rec(k+1, n-k);
  return;
}

int main(void) {
  int n = 0;
  scanf("%d", &n);
  rec(1, n);
  return 0;
}