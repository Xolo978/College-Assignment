#include "linked.h"
#include <stdio.h>

void search(Node *head, int value) {
  if (head == NULL) {
    printf("Not found\n");
    return;
  }
  if (head->data == value) {
    printf("Found value\n");
    return;
  }
  search(head->next, value);
}

int main() {
  Node *head = NULL;
  insert(&head, 1);
  insert(&head, 2);
  search(head, 3);
}
