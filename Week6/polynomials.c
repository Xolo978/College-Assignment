#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
  int coeff;
  int pow;
  struct Node *next;
} Node;

Node *create(int coeff, int pow) {
  Node *new = (Node *)malloc(sizeof(Node));
  new->next = NULL;
  new->coeff = coeff;
  new->pow = pow;
  return new;
}

void insert(int coeff, int pow, Node **head) {
  Node *new = create(coeff, pow);
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

void display(Node *head) {
  if (head == NULL) {
    printf("0");
    return;
  }
  Node *temp = head;
  while (temp != NULL) {
    printf("%dx^%d", temp->coeff, temp->pow);
    if (temp->next != NULL) {
      printf("+");
    }
    temp = temp->next;
  }
  printf("\n");
}

Node *addPoly(Node *h1, Node *h2) {
  Node *h3 = NULL;
  if (h1 == NULL) {
    free(h3);
    return h2;
  }
  if (h2 == NULL) {
    free(h3);
    return h1;
  }
  if (h1->pow > h2->pow) {
    h3 = create(h1->coeff, h1->pow);
    h1 = h1->next;
  } else if (h2->pow > h1->pow) {
    h3 = create(h2->coeff, h2->pow);
    h2 = h2->next;
  } else {
    h3 = create(h2->coeff + h1->coeff, h1->pow);
    h1 = h1->next;
    h2 = h2->next;
  }
  Node *curr = h3;
  while (h1 != NULL && h2 != NULL) {

    if (h1->pow > h2->pow) {
      curr->next = create(h1->coeff, h1->pow);
      curr = curr->next;
      h1 = h1->next;
    } else if (h2->pow > h1->pow) {
      curr->next = create(h2->coeff, h2->pow);
      curr = curr->next;
      h2 = h2->next;
    } else {
      int sum = h1->coeff + h2->coeff;
      if (sum != 0) {
        curr->next = create(sum, h2->pow);
        curr = curr->next;
      }
      h1 = h1->next;
      h2 = h2->next;
    }
  }
  while (h1 != NULL) {
    curr->next = create(h1->coeff, h1->pow);
    curr = curr->next;
    h1 = h1->next;
  }

  while (h2 != NULL) {
    curr->next = create(h2->coeff, h2->pow);
    curr = curr->next;
    h2 = h2->next;
  }
  return h3;
}

Node *multiplyPoly(Node *h1, Node *h2) {
  Node *h3 = NULL;
  if (h1 == NULL || h2 == NULL) {
    return NULL;
  }
  for (Node *x = h1; x != NULL; x = x->next) {
    for (Node *y = h2; y != NULL; y = y->next) {
      {
        int coeff = x->coeff * y->coeff;
        int pow = x->pow + y->pow;
        insert(coeff, pow, &h3);
      }
    }
  }
  return h3;
}

int main() {
  Node *p1 = NULL;
  Node *p2 = NULL;

  insert(5, 3, &p1);
  insert(2, 2, &p1);
  insert(7, 0, &p1);

  insert(3, 3, &p2);
  insert(2, 1, &p2);
  insert(3, 0, &p2);

  printf("Polynomial 1: ");
  display(p1);

  printf("Polynomial 2: ");
  display(p2);

  Node *sum = addPoly(p1, p2);
  printf("Sum: ");
  display(sum);

  Node *product = multiplyPoly(p1, p2);
  printf("Multiplication=: ");
  display(product);

  return 0;
}
