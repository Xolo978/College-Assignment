#ifndef LINKED_H
#define LINKED_H

typedef struct Node {
  int data;
  struct Node *next;
} Node;

void insert(Node **head, int data);
void del(Node **head, int data);

#endif
