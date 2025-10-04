#include "linked.h"
#include <stdio.h>

Node *mid(Node *fast, Node *slow) {
  if (fast == NULL || fast->next == NULL) {
    return slow;
  }
  return mid(fast->next->next, slow->next);
}
