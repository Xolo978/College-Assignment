#include "linked.h"
#include <stdio.h>

Node *merge(Node *h1, Node *h2) {
  if (h1 == NULL) {
    return h2;
  }
  if (h2 == NULL) {
    return h1;
  }
  Node *h3 = NULL;
  if (h1->data <= h2->data) {
    h3 = h1;
    h3->next = merge(h1->next, h2);
  } else if (h2->data <= h1->data) {
    h3 = h2;
    h3->next = merge(h1, h2->next);
  }
  return h3;
}

int main() {
  Node *h1 = NULL;
  Node *h2 = NULL;
  for (int i = 0; i < 5; i++) {
    insert(&h1, i);
    insert(&h2, i + 2);
  }
  printList(h1);
  printList(h2);
  printList(merge(h1, h2));
}
