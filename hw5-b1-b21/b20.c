#include "stdio.h"
#include "math.h"

int main(void) {
  int a;
  scanf("%d", &a);
  if (a < 2) {
    printf("NO\n");
    return 0;
  }
  int sqrta = sqrt((double)a);
  for (int i = 2; i <= sqrta; i++) {
    if (a%i==0) {
      printf("NO\n");
      return 0;
    }
  }
  printf("YES\n");
  return 0;
}:
