#include<stdio.h>
int main(void){
    int n,m,sum=0,tmp,i,j,ans=0;
    scanf("%d%d",&n,&m);
    int a[n];
    /*入力*/
    for(i=0;n>i;++i){
        scanf("%d",&a[i]);
    }
    /*総投票数*/
    for(i=0;n>i;++i){
        sum+=a[i];
    }
    /*降順ソート*/
    for (i=0; i<n; ++i) {
        for (j=i+1; j<n; ++j) {
            if (a[i] < a[j]) {
        tmp =  a[i];
        a[i] = a[j];
        a[j] = tmp;
      }
    }
  }
  /*判定*/
  for(i=0;m>i;++i){
      if(a[i]>(double)sum/(4*m))
      ++ans;
  }
  if(ans==m)
  printf("Yes");
  else
  printf("No");
  return 0;
}