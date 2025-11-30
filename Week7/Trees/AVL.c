#include <stdlib.h>

//The balance factor which is diff btwn the height of ltree and rtree of any node must be [-1,0,1]

//To balance an AVL Tree we need to do LL LR RL  RR Rotations
//LL-> Unbalanced tree when insertion in the left subtree, right rotate once wrt the first imbalanced node
//RR-> Unbalanaced tree when insertion in the right subtree
//LR-> Unbalanced tree wehn insertion of node into right of a left subtree, so do left rotation first and then right
/**RL-> Unbalanced tree wehn insertion of node into left of a right subtree,
so do right rotation wrt child of first inbalanced node first and then left rotate wrt first imbalanced node**/

typedef struct Node
{
  int data;
  struct Node *left;
  struct Node *right;
  int height;
} Node;

int getHeight(Node *node)
{
  if (node == NULL)
  {
    return 0;
  }
  return node->height;
}

Node *create(int data)
{
  Node *new = malloc(sizeof(Node));
  new->data = data;
  new->left = NULL;
  new->right = NULL;
  new->height = 1;
  return new;
}

int balanceFactor(Node *node)
{
  //Diff btwn height of lsubtreee - rsubtree;
  if (node == NULL)
  {
    return 0;
  }
  return (getHeight(node->left) - getHeight(node->right));
}

int max(int a, int b) { return a > b ? a : b; }

Node *rightRotate(Node *y)
{
  Node *x = y->left;
  Node *T2 = x->right;

  x->right = y;
  y->left = T2;

  y->height = max(getHeight(y->left), getHeight(y->right)) + 1;
  x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
  return x;
}

Node *leftRotate(Node *x)
{
  Node *y = x->right;
  Node *T2 = y->left;

  y->left = x;
  x->right = T2;

  y->height = max(getHeight(y->left), getHeight(y->right)) + 1;
  x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
  return y;
}

Node *insert(Node *node, int data)
{
  if (node == NULL)
  {
    return create(data);
  }
  if (data < node->data)
  {
    node->left = insert(node->left, data);
  }
  else if (data > node->data)
  {
    node->right = insert(node->right, data);
  }
  //First height of leaf is caclulated since this is recursive
  node->height = max(getHeight(node->left), getHeight(node->right)) + 1;
  int bf = balanceFactor(node);
  //LL Case:
  //More elements in left means left - right is greater than 1 hence ll case
  if (bf > 1 && data < node->left->data)
  {
    rightRotate(node);
  }

  //RR Case:
  if (bf < -1 && data > node->right->data)
  {
    leftRotate(node);
  }

  //LR Case:
  if (bf > 1 && data > node->left->data)
  {
    node->left = leftRotate(node->left);
    rightRotate(node);
  }
  //RL Case:
  if (bf < -1 && data < node->right->data)
  {
    node->right = rightRotate(node->right);
    leftRotate(node);
  }
  return node;
}
