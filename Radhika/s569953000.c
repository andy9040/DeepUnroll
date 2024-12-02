#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int quick(const void *a, const void *b) {
  return *(int *)a - *(int *)b;
}

int main(void) {
  int n, m, x[100002], mae = 0, ushiro, ans = 0;

  if(scanf("%d %d", &n, &m) == 1);

  ushiro = m - 1;

  for(int i = 0; i < m; i++) {
    if(scanf("%d", &x[i]) == 1);
  }

  qsort(x, m, sizeof(int), quick);

  if(n == 1) {
    ans = abs(x[0] - x[m - 1]);
  } else if(n == 2) {
    mae++;
    ushiro--;
    for(int i = 2; i < m; i++) {
      if(abs(x[mae - 1] - x[mae]) > abs(x[ushiro + 1] - x[ushiro])) {
        ans += abs(x[ushiro + 1] - x[ushiro]);
        ushiro--;
      } else {
        ans += abs(x[mae - 1] - x[mae]);
        mae++;;
      }
    }
  } else {
    mae++;
    ushiro--;
    for(int i = 2; i < n; i++) {
      if(abs(x[mae - 1] - x[mae]) > abs(x[ushiro + 1] - x[ushiro])) {
        mae++;
      } else {
        ushiro--;
      }
    }
    for(int i = n; i < m; i++) {
      if(abs(x[mae - 1] - x[mae]) > abs(x[ushiro + 1] - x[ushiro])) {
        ans += abs(x[ushiro + 1] - x[ushiro]);
        ushiro--;
      } else {
        ans += abs(x[mae - 1] - x[mae]);
        mae++;;
      }
    }
  }

  printf("%d", ans);



  return 0;
}
