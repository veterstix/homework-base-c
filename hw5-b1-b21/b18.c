#include "stdio.h"

int main(void) {
  int a;
  scanf("%d", &a);
  int pred1 = 1, pred2 = 1;
  for (int i = 0; i < a; i++) {
    if (i == 0 || i == 1) {
      printf("%d ", pred1);
      continue;
    }
    int tmp = pred1;
    pred1 += pred2;
    pred2 = tmp;
    printf("%d ", pred1);
  }
  printf("\n");
  return 0;
}
