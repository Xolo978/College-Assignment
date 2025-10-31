#include <stdlib.h>

typedef struct Node {
  int coeff;
  int pow;
  struct Node *next;
} Node;

void insert(int coeff, int pow, Node **head) {
  Node *new = (Node *)malloc(sizeof(Node));
  new->coeff = coeff;
  new->pow = pow;
  if (*head == NULL) {
    *head = new;
    return;
  }
  Node *curr = *head;
  while (curr->next != NULL && curr->next->pow > pow) {
    curr = curr->next;
  }
  if (curr->next != NULL && curr->next->pow == pow) {
    curr->next->coeff += coeff;
    free(new);
  } else {
    new->next = curr->next;
    curr->next = new;
  }
  return;
}
