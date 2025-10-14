void swap(int arr[], int a, int b) {
  int temp = arr[a];
  arr[a] = arr[b];
  arr[b] = arr[a];
}

int partititon(int arr[], int left, int right) {
  int pivot = arr[right];
  int i = left - 1;
  for (int j = left; j < right; j++) {
    if (arr[j] <= pivot) {
      i++;
      swap(arr, i, j);
    }
  }
  swap(arr, right, i + 1);
  return i + 1;
}

void sort(int arr[], int left, int right) {
  if (left < right) {
    int pIdx = partititon(arr, left, right);
    sort(arr, left, pIdx - 1);
    sort(arr, pIdx + 1, right);
  }
}
