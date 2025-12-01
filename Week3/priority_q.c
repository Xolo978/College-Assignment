#include <stdio.h>

#define MAX 100

typedef struct Queue {
  int arr[MAX];
  int size;
} Q;

void swap(int *a, int *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}
// This is for when insertion happens at the end of the array, the last element
// may not ful fill heap property
void heapifyUp(Q *q, int i) {
  int parent = (i - 1) / 2;
  if (i > 0 && q->arr[i] > q->arr[parent]) {
    swap(&q->arr[i], &q->arr[parent]);
    // Since the element is now at its parent's index hence heapifying up with
    // parent
    heapifyUp(q, parent);
  }
}
// This is for when we remove the root or the largest element, we swap the last
// element with the root which might violate heap
void heapifyDown(Q *q, int i) {
  int left = 2 * i + 1;
  int right = 2 * i + 2;
  int largest = i;
  int size = q->size;
  if (left < size && q->arr[left] > q->arr[largest]) {
    largest = left;
  }
  if (right < size && q->arr[right] > q->arr[largest]) {
    largest = right;
  }

  if (largest != i) {
    swap(&q->arr[i], &q->arr[largest]);
    heapifyDown(q, largest);
  }
}

void insert(Q *q, int value) {
  if (q->size == MAX) {
    printf("Full queue\n");
    return;
  }
  q->arr[q->size] = value;
  q->size++;
  // Heapify up from the inserted element
  heapifyUp(q, q->size - 1);
}

int pop(Q *q) {
  if (q->size <= 0) {
    printf("Empty queue\n");
    return -1;
  }
  int max = q->arr[0];
  q->arr[0] = q->arr[q->size - 1];
  q->size--;
  heapifyDown(q, 0);
  return max;
}
