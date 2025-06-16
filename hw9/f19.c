#include <stdio.h>

#define N 5

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
    for (int j = 0; j < N; j++) {
      if (i == j) {
        ans += matrix[i][j];
      }
    }
  }

  double average = (double)ans / (double)N;

  ans = 0;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      if (average < (double)matrix[i][j]) {
        ans++;
      }
    }
  }

  printf("%d", ans);
  
  return 0;
}