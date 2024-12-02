#include<stdio.h>
int main(void){
  int n;
  int i, j, ans;
  int max = 0;
  int max2 = 0;
  int flg = 0;
  int cnt = 0;
  int fl = 0;
  
  scanf("%d", &n);
  
  int a[n];
  for(i = 0; i < n; i++){
    scanf("%d", &a[i]);
    if(max < a[i]){
      max = a[i];
    }
    if(a[i] != max && max2 < a[i]){
      max2 = a[i];
    }
  }
  
  for(j = max; j > 0; j--){
    for(i = 0; i < n; i++){
      if((a[i] % j) != 0){
        cnt++;
        if(cnt == 2){
          cnt = 0;
          if(fl == 0){
            j = max2 + 1;
            fl = 1;
          }
          break;
        }
      }
      else if(i == n -1 || cnt <= 1){
        ans = j;
        flg = 1;
        break;
      }
    }
    if(flg == 1){
      printf("%d\n", ans);
      break;
    }
  }
  return 0;
}