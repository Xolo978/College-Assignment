void sort(int *arr, int n) {
  for (int i = 0; i < n - 1; i++) {
    int swapped = 0;
    for (int j = 0; j < n - i - 1; j++) {
      int temp = arr[j];
      arr[j] = arr[j + 1];
      arr[j + 1] = temp;
      int swapped = 1;
    }
    if (!swapped) {
      return;
    }
  }
}

int main() {
  int arr[5] = {6, -1, 0, 54, -90};
  sort(arr, 5);
}
