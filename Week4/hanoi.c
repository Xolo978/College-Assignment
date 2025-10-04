#include <stdio.h>

void hanoi(int n, char src, char aux, char dest) {
  if (n == 0)
    return;
  if (n == 1) {
    printf("1 Disk moved from %c to %c\n", src, dest);
    return;
  }
  // Moving n-1 disks from src to aux taking dest as helper
  hanoi(n - 1, src, dest, aux);
  // Moving largest(nth) disk from src to dest
  printf("Moved %d from %c to %c\n", n, src, dest);
  // Moving n-1 disks from aux to dest taking src as helper
  hanoi(n - 1, aux, src, dest);
}

int main() {
  char src = 'A';
  char aux = 'B';
  char dest = 'C';
  hanoi(3, src, aux, dest);
}
