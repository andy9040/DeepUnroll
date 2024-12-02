#include <stdio.h>

int main()
{
  int n;

  scanf("%d", &n);

  int L, R;
  int ans = 0;
  for (int i = 0; i < n; i++) {
    scanf("%d %d", &L, &R);
    int x = R - L + 1;
    ans += x;
  }

  printf("%d\n", ans);


  return 0;
}
