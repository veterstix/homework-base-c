void change_max_min(int size, int a[]) {
  int max = a[0];
  int max_idx = 0;
  int min = a[0];
  int min_idx = 0;

  for (int i = 0; i < size; i++) {
    if (max < a[i]) {
      max = a[i];
      max_idx = i;
    }

    if (min > a[i]) {
      min = a[i];
      min_idx = i;
    }
  }

  a[max_idx] = min;
  a[min_idx] = max;
}