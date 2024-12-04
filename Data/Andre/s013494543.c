#include <stdio.h>

int main(void) {
  int n;
  scanf("%d", &n);
  long ans = 0;
  for(int i = 1;i <= n;i++) {
    int y = n / i;
    ans += y * (y + 1) * i / 2;
  }
  printf("%ld\n", ans);
  return 0;
}
