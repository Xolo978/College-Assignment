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
  struct Node *new = (Node *)malloc(sizeof(Node));
  new->data = data;
  new->left = NULL;
  new->right = NULL;
  return new;
}

Node *insert(Node *root, int value)
{
  if (root == NULL)
  {
    return create(value);
  }
  //Since all values in left subtree is less than the value of root
  if (value < root->data)
  {
    root->left = insert(root, value);
  }
  else if (value > root->data)
  {
    root->right = insert(root, value);
  }
  //Now return new root
  return root;
}

void inorder(Node *root)
{
  if (root == NULL)
  {
    return;
  }
  inorder(root->left);
  printf("%d", root->data);
  inorder(root->right);
}

Node *search(Node *root, int value)
{
  if (root == NULL || root->data == value)
  {
    return root;
  }
  if (value > root->data)
  {
    return search(root->right, value);
  }
  else
  {
    return search(root->left, value);
  }
}

//For finding the min of a subtree(going left since thats the property of bst left<node)
Node *findMin(Node *root)
{
  while (root && root->left != NULL)
  {
    root = root->left;
  }
  return root;
}

Node *deleteNode(Node *root, int key)
{
  if (root == NULL)
  {
    return NULL;
  }
  //Find the key and backtrack by fixing the nodes
  if (key < root->data)
  {
    root->left = deleteNode(root->left, key);
  }
  else if (key > root->data)
  {
    root->right = deleteNode(root, key);
  }
  //Data neither greather nor lesser hence we found the data
  else
  {
    if (root->left == NULL && root->right == NULL)
    {
      free(root);
      return NULL;
    }
    else if (root->left == NULL)
    {
      Node *temp = root->right;
      //Replace the node with its child and free the child
      root = root->right;
      free(temp);
      return root;
    }

    else if (root->right == NULL)
    {
      Node *temp = root->left;
      root = root->left;
      free(temp);
      return root;
    }
    else
    {
      //Get min from right subtree
      Node *min = findMin(root->right);
      //We replace the found data with the min of the right trr
      root->data = min->data;
      //We delete the min data(duplicate) from the right subtree
      root->right = deleteNode(root->right, min->data);
    }
  }
  return root;
}
