// Функция Аккермана

#include <stdio.h>

int akkerman(int n, int m) {
  if (n != 0) {
    if (m == 0) {;
      return akkerman(n-1, 1);
    } else {
      return akkerman(n-1, akkerman(n, m -1));
    }
  } else {
    return m+1;
  }
}

int main(void) {
  int n, m = 0;
  scanf("%d %d", &n, &m);
  printf("%d", akkerman(n, m));
  return 0;
}