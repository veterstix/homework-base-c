#include <stdio.h>


int main(void) {
  int matrix[5][5] = {0};

  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 5; j++) {
      // scanf("%d", &(matrix[i][j]));
      scanf("%d", matrix[i] + j); // mojno
    }
  }

  int ans = 0;
  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 5; j++) {
      if (i == j) {
        ans += matrix[i][j];
      }
    }
  }

  printf("%d", ans);
  
  return 0;
}