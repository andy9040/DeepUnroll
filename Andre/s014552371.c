#include <stdio.h>
int main(void) {
  long long n,m[30],k,ans[30];
  int i,j,d;
  scanf("%lld",&n);
  m[30]=n;
  for(i=30;i>=1;i--){
    if(m[i]<0) m[i]=-m[i];
    k=1;
    for(j=1;j<=i;j++){
      k=k*(-2);
    }
    if(k<0) k=-k;
    if(m[i]>=k) ans[i]=1;
    else ans[i]=0;
  }
  d=30;
  while(ans[d]=0) do{d--;}
  for(i=d;i>=1;i--){
    printf("%d",ans[i]);
  }
  return 0;
}