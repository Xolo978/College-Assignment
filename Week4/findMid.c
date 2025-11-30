#include "linked.h"
#include <stdio.h>

Node *mid(Node *fast, Node *slow) {
  if (fast == NULL || fast->next == NULL) {
    return slow;
  }
  return mid(fast->next->next, slow->next);
}

int main() {
  Node *h = NULL;
  insert(&h, 1);
  insert(&h, 2);
  insert(&h, 3);
  insert(&h, 4);
  insert(&h, 5);
  printf("%d\n", mid(h, h)->data);
}
