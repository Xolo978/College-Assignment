#include <stdio.h>

void merge(int arr[], int left, int mid, int right) {
  int i = left;    // start of left half
  int j = mid + 1; // start of right half
  int temp[] = {};
  int k = 0;
  while (i <= mid && j <= right) {
    if (arr[i] <= arr[j]) {
      temp[k++] = arr[i++];
    } else {
      temp[k++] = arr[j++];
      j++;
    }
  }
  // Push back remaining elements
  while (i <= mid) {
    temp[k++] = arr[i++];
  }
  while (j <= right) {
    temp[k++] = arr[j++];
  }
  int size = sizeof(temp) / sizeof(temp[0]);
  // Till here we have sorted the array[left...right] range
  // Here we need to add back those elements within the left to right range
  // Hence we need to add left as the offset
  for (int t = 0; t < size; t++) {
    arr[t + left] = temp[t];
  }
}

void mergeSort(int arr[], int left, int right) {
  if (left < right) {
    int mid = left + (right - left) / 2;
    mergeSort(arr, left, mid);      // Sort left half first
    mergeSort(arr, mid + 1, right); // Sort right half then
    merge(arr, left, mid, right);
  }
}

int main() {
  int arr[5] = {6, -1, 0, 7, 2};
  mergeSort(arr, 0, 4);
  for (int i = 0; i < 5; i++) {
    printf("%d\n", arr[i]);
  }
}
