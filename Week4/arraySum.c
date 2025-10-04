#include <stdio.h>

int arraySum(int arr[], int n) {
  if (n == 0) {
    return 0;
  }

  return arr[n - 1] + arraySum(arr, n - 1);
}

int main() {
  int arr[3] = {0, 1, 2};
  int sum = arraySum(arr, 3);
  printf("%d", sum);
}
