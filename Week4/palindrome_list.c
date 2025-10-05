#include "linked.h"
#include <stdio.h>

int check(Node **left, Node *right) {
  if (right == NULL) {
    return 1;
  }
  int end = check(left, right->next);
  if (end == 0) {
    return 0;
  }
  // 1 if matched else 0
  int matched = ((*left)->data == right->data);
  *left = (*left)->next;
  return matched;
}

int isPalindrome(Node *head) { return check(&head, head); }

int main() {
  Node *head = NULL;
  insert(&head, 0);
  insert(&head, 1);
  insert(&head, 1);
  if (isPalindrome(head)) {
    printf("Palindrome\n");
  } else {
    printf("Not Palindrome\n");
  }
}
