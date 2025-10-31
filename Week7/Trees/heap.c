/**Its a complete binary tree
 Max Heap -> Parent >= child, which means root is always greatest element
 Min Heap -> Parent <= child, which means root is always smallest element

 Heaps always implemented using arrays since they are dense tree
 Indexing rules->
    left child = (2*i)+1
    right child = (2*i)+2
    parent node = (i-1)/2
* **/

#include <limits.h>
#define MAX 100

int parent(int i) { return (i - 1) / 2; }

int left(int i) { return (2 * i) + 1; }

int right(int i) { return (2 * i) + 2; }

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

//Intuition for insering could be thought like this->
/**
1. Place new element at the end
2. Check if the element > parent;
3. If yes then swap and move up to the parent's index and recheck again if > parent
4. We can say we are bubbling up or heapifying up.
* **/

void insert(Heap *h, int val)
{
  int i = h->size;
  h->arr[i] = val;
  h->size++;
  while (i != 0 && h->arr[i] > h->arr[parent(i)])
  {
    swap(h->arr, h->arr[i], h->arr[parent(i)]);
    i = parent(i);
  }
}

/**
 The intuition behind this is
  1.Find left and right of that node
  2.Check if left and right exist
  4.If they do then check if its larger than the current node
  5.If yes then swap then
  6.Move down if the swap occured
  **/
void heapifyDown(Heap *h, int i)
{
  int largest = i;
  while (1)
  {
    int l = left(i);
    int r = right(i);
    //l or r could be out of bounds since not all the elements of the arr have a left or right node
    //hence checking if l or r is greater than size
    if (l < h->size && h->arr[l] > h->arr[i])
      largest = l;
    if (r < h->size && h->arr[r] > h->arr[i])
      largest = r;
    if (largest == i)
      break;
    swap(h->arr, i, largest);
    //If l or r whichever is bigger is now the largest then move down and set i to largest
    i = largest;
  }
}

int extractMax(Heap *h)
{
  if (h->size == 0)
    return INT_MIN;
  int result = h->arr[0];
  int size = h->size;
  //This is simply moving the last element to the root
  h->arr[0] = h->arr[size - 1];
  h->size--;
  heapifyDown(h, 0);
  return result;
}
