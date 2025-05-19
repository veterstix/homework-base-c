// Составить функцию вычисления N!

#include <stdio.h>

// recursive method
int factorial_rec(int n) {
  if (n==0) {
    return 1;
  }
  return n*factorial_rec(n-1);
}

// iterative method
int factorial(int n) {
  int fact = 1;

  while (n > 0) {
    fact *= n--;
  }

  return fact;
}

int main(void) {
  int num = 0;
  scanf("%d", &num);
  printf("%d\n", factorial(num));
  return 0;
}