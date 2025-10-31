#include <stdio.h>
#include <stdlib.h>

/**
Binary tree only has 2 max child nodes
Max nodes for a level i = 2^i
Max nodes for a height h = 2^(h+1)-1
Min nodes for a height h = h+1
**/
typedef struct Node
{
  int data;
  struct Node *left;
  struct Node *right;
} Node;

struct Node *create(int data)
{
  struct Node *new = (Node *)malloc(sizeof(Node));
  new->data = data;
  new->left = NULL;
  new->right = NULL;
  return new;
}

void preorder(Node *root)
{
  if (root == NULL)
    return;
  printf("%d ", root->data);
  preorder(root->left);
  preorder(root->right);
}

void inorder(Node *root)
{
  if (root == NULL)
  {
    return;
  }
  inorder(root->left);
  printf("%d ", root->data);
  inorder(root->right);
}

void postorder(Node *root)
{
  if (root == NULL)
  {
    return;
  }
  inorder(root->left);
  inorder(root->right);
  printf("%d ", root->data);
}

//Defining height by number of edges
int height(Node *node)
{
  if (node == NULL)
  {
    return -1;
  }
  else
  {
    int lHeight = height(node->left);
    int rHeight = height(node->right);
    //Return max of either of them +1 for the current node
    if (lHeight > rHeight)
    {
      return lHeight + 1;
    }
    else
    {
      return rHeight + 1;
    }
  }
}

int leafNodes(Node *node)
{
  if (node == NULL)
  {
    return 0;
  }
  //Leaf Node found
  if (node->left == NULL && node->right == NULL)
  {
    return 1;
  }
  return leafNodes(node->right) + leafNodes(node->left);
}

int main()
{
  Node *root = create(1);
  root->left = create(2);
  root->right = create(3);
  root->left->left = create(4);
  root->right->left = create(7);
  preorder(root);
  printf("\n");
  printf("Height is %d\n", height(root));
  printf("Number of leaf nodes are %d\n", leafNodes(root));
  return 0;
}

/**  A
    / \
   B   C
**/

/** Pre-order traversal-> Basically means Pre-Order traversal as in go from parent->child (A->B->C)
 Inorder traversal-> Basically means visit left child then parent and then right child (B->A->C)
 Postorder traversal-> Visit children first and then parent (B->C-A)
 Levelorder traversal-> Visit level by level (A->B->C)
 **/
