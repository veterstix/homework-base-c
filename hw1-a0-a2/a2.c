#include <stdio.h>

//   *
//  ***
// *****
//*******
// HHOHH
// ZZZZZ

int main(void) {
  #define size_spruce 20 // set the height spruce
  int space = size_spruce - 1;
  int stars = 1;
  for (int i = 0; i < size_spruce; i++) {
    int tmp = space;
    while (tmp != 0) {
      printf(" ");
      tmp--;
    }
    int j = 0;
    while (j != stars ) {
      printf("*");
      j++;
    }
    printf("\n");
    space--;
    stars +=2;
  }

  for (int i = 0; i < size_spruce*2 - 2; i++) {
    if (i == size_spruce-1) {
      printf("O");
    } else if (i == 0) {
      printf(" ");
    } else {
      printf("H");
    }
  }
  printf("\n");

  for (int i = 0; i < size_spruce*2 - 2; i++) {
    if (i == 0) {
      printf(" ");
    } else {
      printf("Z");
    }
  }
  printf("\n");

  return 0;
}