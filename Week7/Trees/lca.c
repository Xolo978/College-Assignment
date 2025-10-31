#include <inttypes.h>
#include <stdlib.h>

typedef struct Node
{
  int data;
  struct Node *left;
  struct Node *right;
} Node;

/**
Intuiton is like this ->
Considering this bst
        50
       /  \
     30    70
    / \    / \
   20 40  60 80

 1. We need to find LCA(20,40) which is 30
 2. For any node node->left < node < node->right
 3. Hence this means we want the node between n1 qnd n2
 4. One node is in the left subtree while the other in the right, which is the split point
 5. Lets pick 50 as the starting node for this
 6. Since 20< 50 aand 40<50 hence both the nodes are on the left subtree which cannot be as it violates the point 4
 7. Now root = 30 and since 20 <30(left subtree) and 40>30(right subtree) hence we have a split
 8. Hence 30 is the answer
**/

Node *LCA(Node *root, int n1, int n2)
{
  if (root == NULL)
  {
    return root;
  }
  //If both are greater go right subtree
  if (n1 > root->data && n2 > root->data)
  {
    return LCA(root->right, n1, n2);
  }
  //If both are smaller go left subtree
  if (n1 < root->data && n2 < root->data)
  {
    return LCA(root->left, n1, n1);
  }
  //Otherwise split point found
  return root;
}
