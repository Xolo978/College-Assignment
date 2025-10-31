#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
  int data;
  struct Node *left;
  struct Node *right;
} Node;

Node *create(int data)
{
  Node *new = (Node *)malloc(sizeof(Node));
  new->data = data;
  new->left = NULL;
  new->right = NULL;
  return new;
}
//Doing an inorder traversal
int checkBST(Node *root, int *prev)
{
  if (root == NULL)
  {
    return 1;
  }
  if (checkBST(root->left, prev) != 1)
  {
    return 0;
  }
  if (root->data <= *prev)
  {
    return 0;
  }
  *prev = root->data;

  return checkBST(root->right, prev);
}

int isBST(Node *root)
{
  int prev = INT_MIN;
  return checkBST(root, &prev);
}

int main()
{
  Node *root = create(10);
  root->left = create(5);
  root->right = create(15);
  root->left->left = create(3);
  root->left->right = create(7);

  if (isBST(root))
    printf("Tree is a BST\n");
  else
    printf("Tree is not a BST\n");
}
