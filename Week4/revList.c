#include "linked.h"
#include <stdio.h>

Node *rev(Node *head) {
  if (head == NULL || head->next == NULL) {
    return head;
  }
  // Last node
  Node *new = rev(head->next);
  Node *front = head->next;
  front->next = head;
  head->next = NULL;
  return new;
}
