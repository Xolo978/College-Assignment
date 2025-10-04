#include <stdio.h>

void rev(char *str, int start, int end) {
  if (start >= end) {
    return;
  }
  char temp = str[start];
  str[start] = str[end];
  str[end] = temp;
  rev(str, start + 1, end - 1);
}

int main() {
  char str[] = "ABCD";
  rev(str, 0, 3);
  printf("%s\n", str);
}
