// Проверить строку состоящую из скобок "(" и ")" на корректность.
// Input:
// (()()).
// Output:
// YES
#include <stdio.h>

int main(void) {
  char ch = 0;
  int balance = 0;
  while (scanf("%c", &ch) && ch != '.') {
    if (ch == '(') {
      balance++;
    } else {
      balance--;
    }
    
    if (balance < 0) {
      printf("NO\n");
      return 0;
    }
  }
  
  if (balance == 0) {
    printf("YES\n");
    return 0; 
  }

  printf("NO\n");
  return 0;
}