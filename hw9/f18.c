#include <stdio.h>

#define N 10

int main(void) {
  int matrix[N][N] = {0};

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      // scanf("%d", &(matrix[i][j]));
      scanf("%d", matrix[i] + j); // mojno
    }
  }

  int ans = 0;
  for (int i = 0; i < N; i++) {
    int max = matrix[i][0];
    for (int j = 0; j < N; j++) {
      if (matrix[i][j] > max) {
        max = matrix[i][j];
      }
    }
    ans += max;
  }

  printf("%d", ans);
  
  return 0;
}