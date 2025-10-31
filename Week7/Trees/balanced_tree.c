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

int height(Node *root)
{
  if (root == NULL)
  {
    return -1;
  }

  int leftH = height(root->left);
  int rightH = height(root->right);
  if (leftH - rightH > 1)
  {
    return -1;
  }
  return 1 + (leftH > rightH ? leftH : rightH);
}

int isBalanced(Node *root) { return height(root) != -1; }

int main()
{
  Node *root = create(10);
  root->left = create(5);
  root->right = create(20);
  root->left->left = create(3);
  root->left->right = create(8);
  if (isBalanced(root))
    printf("Tree is balanced\n");
  else
    printf("Tree is not balanced\n");

  return 0;
}
