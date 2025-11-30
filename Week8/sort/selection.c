#include <stdio.h>
/**Selection sort is nothing but dividing the array into sorted and unsorted
 part Initially there is only unsorted part We pick smallest element from the
 unsorted part and then swap with the first element in the unsorted part This
 increases the sorted part and decrease the unsorted part
 **/
void sort(int *arr, int n) {
  // By the time we reach last element the last two elements would already be
  // sorted since the second last element must be <= last according to the algo
  for (int i = 0; i < n - 1; i++) {
    // Take smallest as the current element(i to n-1 is unsorted) and then find
    // the smallest element from then onwards
    int smallest = i;
    for (int j = i + 1; j < n; j++) {
      if (arr[j] < arr[smallest]) {
        smallest = j;
      }
    }
    // Now swap the smallest element with the 1st element in the unsorted part
    // which is ith index
    int temp = arr[i];
    arr[i] = arr[smallest];
    arr[smallest] = temp;
  }
}

void recurseSort(int arr[], int n, int start) {
  // Start is the start of the unsorted array
  int minId = start;
  for (int i = start; i < n; i++) {
    if (arr[i] < arr[minId]) {
      minId = i;
    }
  }
  // Now that we have the minElement from the unsorted part we can now swap with
  // the start element
  int temp = arr[start];
  arr[start] = arr[minId];
  arr[minId] = temp;
  // Do this thing for the rest of the array
  recurseSort(arr, n, start + 1);
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

  sort(arr, n);

  printf("Sorted array: ");
  printArray(arr, n);

  return 0;
}
