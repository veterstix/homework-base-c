#include <stdio.h>

static void print_array(int arr[], int sz) {
  int i = 0;
  while (i < sz) {
    printf("%d ", arr[i]);
    i++;
  }
  printf("\n");
}

int compression(int a[], int b[], int N) {
  int k = 0;

  if (a[0] == 1) {
    b[k] = 0;
    k++;
  }

  int i = 0;
  while (i < N) {
    int count = 0;
    int fix = a[i];

    while (i < N && fix == a[i]) {
      count++;
      i++;
    }

    if (count) {
      b[k] = count;
      k++; 
    }
  }

  return k;
}

int main() {
  int a[12] = {0,1,0,0,0,1,1,1,1,0,0,1};
  int b[12] = {0};
  

  int k = compression_function(a, b, 12);

  print_array(b,k);

  return 0;
}