int find_max_array(int size, int a[]) {
  int max = a[0];

  for (int i = 0; i < size; i++) {
    if (max < a[i]) {
      max = a[i];
    }
  }
  return max;
}