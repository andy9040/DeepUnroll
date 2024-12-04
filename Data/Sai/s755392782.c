#include<stdio.h>
int main() {
  int i, k, n, m, cnt, data[100], data2[100][100], data3[100] = {0};
  scanf("%d %d", &n, &m);
  for(i = 0; i < m; i++) {
    scanf("%d", &data[i]);
  }
  for(i = 0; i < m; i++) {
    for(k = 0; k < n; k ++) {
      scanf("%d", &data2[i][k]);
    }
  }
  for(i = 0; i < m; i++) {
    cnt = 0;
    for(k = 0; k < n; k++) {
      if(data[i] == data2[i][k]) {
        data3[k]++;
        if(k == 1) {
        }
      }else{
        data3[data[i] - 1]++;
      }
    }
  }
  for(i = 0; i < n ; i++) {
    printf("%d\n",data3[i]);
  }
  return 0;
}
  