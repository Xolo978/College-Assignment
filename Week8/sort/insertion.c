#include <stdio.h>

void insertionSort(int arr[], int n) {
  int i, j, key;
  for (int i = 1; i < n; i++) {
    // Chose the element
    int curr = arr[i];
    // Then pick the starting point of comparison which is before the curr
    // element's index From this index onwards we shift the elements towards
    // right till we find the correct place for the curr element
    int prev = i - 1;
    // Go over as long as we dont hit the first element and beyond and as long
    // as the prev elements are grater than the curr element

    while (j >= 0 && arr[j] > curr) {
      // Shift the elements towards right
      arr[j + 1] = arr[j];
      j = j - 1;
    }
    // Found the position for the curr elements
    arr[j + 1] = key;
  }
}

void printArray(int arr[], int n) {
  for (int i = 0; i < n; ++i) {
    printf("%d ", arr[i]);
  }
  printf("\n");
}

int main() {
  int arr[] = {12, 11, 13, 5, 6, 7};
  int n = sizeof(arr) / sizeof(arr[0]);

  printf("Original array: ");
  printArray(arr, n);

  insertionSort(arr, n);

  printf("Sorted array: ");
  printArray(arr, n);

  return 0;
}
