#include "stdio.h"

int main(void) {
  int m;
  scanf("%d", &m);
  char months[12][20] = {"winter", "winter",
                         "spring", "spring", "spring",
                         "summer", "summer", "summer", 
                         "autumn", "autumn", "autumn",
                         "winter"};
  if (m >= 1 && m <= 12) {
    printf("%s\n", months[m-1]);
  }
  return 0;
}