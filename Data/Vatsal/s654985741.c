#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//#include <stdbool.h>
//#include <limits.h>
//#include <math.h>

#define MOD 1000000007

int main() {
  int n;
  scanf("%d", &n);
  long a[n], ans = 0;
  int cnt1[60] = {0};
  for (int i=0; i<n; i++) {
    scanf("%ld", a+i);
    for (int j=0; j<60; j++)
      if ((a[i]&(1ull<<j)) != 0) cnt1[j]++;
  }
  for (int i=0; i<60; i++) {
    ans += (((cnt1[i] * (n - cnt1[i])) % MOD) * ((1ull << i) % MOD)) % MOD;
    ans %= MOD;
  }
  printf("%ld\n", ans);
  return 0;
}
