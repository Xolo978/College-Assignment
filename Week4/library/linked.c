#include "linked.h"
#include <stdio.h>
#include <stdlib.h>

void insert(Node **head, int data) {
  Node *new = (Node *)malloc(sizeof(Node));
  new->data = data;
  new->next = NULL;
  if (*head == NULL) {
    *head = new;
    return;
  }
  Node *temp = *head;
  while (temp->next != NULL) {
    temp = temp->next;
  }
  temp->next = new;
}

void del(Node **head, int data) {
  if (*head == NULL) {
    return;
  }
  if ((*head)->data == data) {
    Node *temp = *head;
    *head = (*head)->next;
    free(temp);
    return;
  }
  Node *prev = *head;
  Node *curr = (*head)->next;
  while (curr != NULL && curr->data != data) {
    prev = curr;
    curr = curr->next;
  }
  if (curr == NULL) {
    return;
  }
  prev->next = curr->next;
  free(curr);
  return;
}

void printList(Node *head) {
  if (head == NULL) {
    printf("Empty list");
    return;
  }
  Node *temp = head;
  printf("\n");
  while (temp != NULL) {
    printf("%d->", temp->data);
    temp = temp->next;
  }
  printf("NULL");
}
