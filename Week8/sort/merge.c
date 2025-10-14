#include <stdio.h>

void merge(int arr[], int left, int mid, int right) {
  int s1 = mid - left + 1;
  int s2 = right - mid;
  int L[s1];
  int R[s2];
  // Add elements from left to mid to left array
  for (int i = 0; i < s1; i++) {
    L[i] = arr[left + i];
  }
  for (int j = 0; j < s2; j++) {
    R[j] = arr[mid + 1 + j];
  }
  int i = 0;
  int j = 0;
  int k = left; // Merging from arr[left till right]
  while (i < s1 && j < s2) {
    if (L[i] >= R[j]) {
      arr[k] = L[i];
      i++;
    } else {
      arr[k] = R[j];
      j++;
    }
    k++;
  }
  while (i < s1) {
    arr[k] = L[i];
    k++;
    i++;
  }
  while (j < s2) {
    arr[k] = R[j];
    k++;
    j++;
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
