#include "linked.h"
#include <stdio.h>

void find(Node *head, int data) {
  if (head == NULL) {
    printf("Not found");
    return;
  }
  if (head->data == data) {
    printf("Found\n");
    return;
  }
  find(head->next, data);
}
