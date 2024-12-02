#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#define Max(a, b) ((a) > (b) ? (a) : (b))
#define Min(a, b) ((a) > (b) ? (b) : (a))
#define REP(i, n) for(int i = 0; i < n; i++)
typedef long long ll;

int dsc(const void *a, const void *b){
  return *(int *)b - *(int *)a;
}

int
main(int argc, char *argv[])
{
  int n, h, a, amax = -1, b[100001];
  scanf("%d %d", &n, &h);
  REP(i, n){
    scanf("%d %d", &a, &b[i]);
    amax = Max(amax, a);
  }

  qsort(b, n, sizeof(int), dsc);

  int k = 0, ans = 0;
  while(h > 0){
    if(b[k] > amax){
      h -= b[k++];
      ans++;
    }else{
      ans += (h - 1) / amax + 1;
      break;
    }
  }

  printf("%d\n", ans);

  return 0;
}
