#include <stdio.h>

void swap(char *s, int l, int r) {
  char temp = s[l];
  s[l] = s[r];
  s[r] = temp;
}

void permute(char *s, int l, int r) {
  if (l >= r) {
    printf("%s\n", s);
  }
  for (int i = l; i <= r; i++) {
    swap(s, l, i);
    permute(s, l + 1, r);
    swap(s, l, i);
  }
}

int main() {
  char s[] = "ABC";
  permute(s, 0, 2);
}
