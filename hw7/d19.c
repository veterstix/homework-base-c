// Сколько раз встречается символ a

#include <stdio.h>

int acounter(void) {
  char ch;
  scanf("%c", &ch);
  if (ch == '.') {
    return 0;
  }
  return ((ch == 'a') ? 1 : 0) + acounter();
}


int main(void) {
  printf("%d\n", acounter());
  return 0;
}