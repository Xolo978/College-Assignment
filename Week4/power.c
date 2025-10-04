#include <stdio.h>

float power(float base, int raise) {
  if (raise == 0) {
    return 1;
  }
  if (raise < 0) {
    base = (float)1.0 / base;
    raise = -raise;
  }
  return base * power(base, raise - 1);
}

int main() {
  float base = 2;
  int raise = -1;
  float result = power(base, raise);
  printf("%.2f\n", result);
}
