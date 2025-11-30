#include <stdio.h>

void insertionSort(int arr[], int n) {
  int i, j, key;
  for (int i = 1; i < n; i++) {
    // Chose the element
    int key = arr[i];
    // Then pick the starting point of comparison which is before the curr
    // element's index From this index onwards we shift the elements towards
    // right till we find the correct place for the curr element
    // From j and before we have the sorted array
    int j = i - 1;
    // Go over as long as we dont hit the first element and beyond and as long
    // as the prev elements are greater than the curr element
    while (j >= 0 && arr[j] > key) {
      // Shift the elements towards right and make space for the curr element
      arr[j + 1] = arr[j];
      // Keep looking for its correct place
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

void recursiveSort(int arr[], int n) {
  if (n <= 1)
    return;
  // First recursively sort n-1 elements
  recursiveSort(arr, n - 1);
  // Get the last item from the sorted array(which is not yet sorted probably
  // and is our target to sort or the current element)
  int key = arr[n - 1];
  // This is the last element from the sorted part
  int j = n - 2;
  // Keep shifting till we get the position
  // https://www.youtube.com/watch?v=A8DPwEk8Has
  while (j >= 0 && arr[j] > key) {
    arr[j + 1] = arr[j];
    j = j - 1;
  }
  arr[j + 1] = key;
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
