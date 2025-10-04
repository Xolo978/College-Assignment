#include <stdio.h>

void check(char *str, int start, int end) {
  if (start >= end) {
    printf("Palindrome\n");
    return;
  }
  if (str[start] != str[end]) {
    printf("Not palindrome\n");
    return;
  }
  check(str, start + 1, end - 1);
}

int main() {
  char s[] = "ABD";
  check(s, 0, 2);
}
