#include <stdio.h>

int main() {
  int x, N;
  scanf("%d", &N);
  if (N == 0)
    x = 0;
  else
    x = (-N % 1000);
  printf("%d\n", x);

  return 0;
}
