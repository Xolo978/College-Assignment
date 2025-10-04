#include "linked.h"
#include <stdlib.h>

int length(Node *head) {
  if (head == NULL) {
    return 0;
  }
  return 1 + length(head->next);
}
