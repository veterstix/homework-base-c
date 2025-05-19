// Составить рекурсивную функцию.
// Выведите все числа от A до B включительно, в порядке возрастания, ...
// если A < B, или в порядке убывания в противном случае.

#include <stdio.h>

void rec(int a, int b) {
  printf("%d ", a);
  if (a == b) {
    return;
  }

  if (a > b) {
    rec(a-1, b);
  } else {
    rec(a+1, b);
  }
}

int main(void) {
  int a, b = 0;
  scanf("%d %d", &a, &b);
  rec(a, b);
  return 0;
}