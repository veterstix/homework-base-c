#include <stdio.h>

int count_bigger_abs(int n, int a[]) {
  int max = a[0];

  for (int i = 1; i < n; i++) {
    if (a[i] > max) {
      max = a[i];
    }
  }
  
  int ans = 0;
  for (int i = 0; i < n; i++) {
    if (a[i] < 0 && -a[i] > max) {
      ans++;
    }
  }

  return ans;
}

int main(void) {
  int a[10] = {-47,19,8,-41,24,22,44,23,28,-29};

  printf("%d\n", count_bigger_abs(10, a));
  
  return 0;
}