#include <limits.h>
#include <stdio.h>
#define MAX 100
int left(int i) { return (2 * i) + 1; }
int right(int i) { return (2 * i) + 2; }
int parent(int i) { return (i - 1) / 2; }
typedef struct
{
  int arr[MAX];
  int size;
} Heap;

void swap(int *arr, int a, int b)
{
  int temp = arr[a];
  arr[a] = arr[b];
  arr[b] = temp;
}
//Imp point of this thing is this thing assumes that the subtrees itself are valid heaps
void heapifyDown(int arr[], int n, int i)
{
  int largest = i;
  while (1)
  {
    int l = left(i);
    int r = right(i);
    if (l < n && arr[l] > arr[largest])
      largest = l;
    if (r < n && arr[r] > arr[largest])
      largest = r;
    if (largest == i)
    {
      break;
    }
    swap(arr, i, largest);
    i = largest;
  }
}

/**
 makeHeap concept is that
 1. We find the last non-leaf node(node containg atleast (one child).
 2. Which is done by (n-2)/2 since we know parent can be received through (i-1)/2 and i is n-1 here;
 3. This ensures that as we go up the tree the subtrees are valid heap which is needed for the heapifyDown method at the top
  **/
void makeHeap(int arr[], int n)
{
  for (int i = (n / 2 - 1); i >= 0; i--)
  {
    heapifyDown(arr, n, i);
  }
}

void heapSort(int arr[], int n)
{
  //Ensure heap is valid
  makeHeap(arr, n);
  for (int i = n - 1; i > 0; i--)
  {
    swap(arr, 0, i);
    heapifyDown(arr, i, 0);
  }
}

int main(void)
{
  int arr[7] = {10, 20, 25, 60, 30, 58, 71};
  heapSort(arr, 7);
  int i = 0;
  while (i < 7)
  {
    printf("%d\n", arr[i]);
    i++;
  }
}
