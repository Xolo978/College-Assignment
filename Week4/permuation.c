#include <stdio.h>

void swap(char *s, int l, int r) {
  char temp = s[l];
  s[l] = s[r];
  s[r] = temp;
}

void permute(char *s, int l, int r) {
  if (l >= r) {
    printf("%s", s);
  }
  for (int i = 0; i <= r; i++) {
    swap(s, l, i);
    permute(s, l + 1, r);
    swap(s, l, i);
  }
}

int main() {
  char s[] = "ABCD";
  permute(s, 0, 3);
}
