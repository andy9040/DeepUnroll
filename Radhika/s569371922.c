#include <stdio.h>

int main() {
  int n, p, i, j, k, flag;
  int cnd[50];

  while(1) {
    flag = 0;
    for(i = 0; i < 50; i++) {
      cnd[i] = 0;
    }
    scanf("%d %d", &n, &p);
    if(n == 0 && p == 0){
      break;
    }
    else if(n < 3 || n > 50 || p < 2 || p > 50) {
      scanf("%d %d", &n, &p);
    }
    j = p;
    while(1) {
      printf("a\n");
      for(i = 0; i < n; i++) {
        if(j > 0) {
          cnd[i] += 1;
          j--;
          if(cnd[i] == p) {
            printf("%d\n", i);
            flag = 1;
            break;
          }
        }
        else if(cnd[i] > 0) {
          cnd[i] -= 1;
          j++;
        }
      }
      if(flag == 1)
        break;
    }
  }

  return 0;
}