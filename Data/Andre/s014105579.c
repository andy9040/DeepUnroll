#include <stdio.h>

int count5(int n) {
  int t = 0, i;
  for (i = 5; i <= n; i *= 5)
    t += n / i;

  return t;
}

int main(void) {
  int n, num0;

  while (1) {
    scanf("%d", &n);
    if (n == 0) break;

    num0 = count5(n);
    printf("%d\n", num0);
  }
  return 0;
}