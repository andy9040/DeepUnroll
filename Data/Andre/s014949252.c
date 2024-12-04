#include <stdio.h>
#define dr 998244353

int main(){
  int n,m,k,i,j,l[200005]={};
  long mm=0;
  scanf("%d",&n);
  scanf("%d",&m);
  scanf("%d",&k);
  for(i=0;i<n;i++){
    l[0]*=m-1;
    l[0]%=dr;
    for(j=1;j<=k;j++){
      l[j]*=m-1;
      l[j]+=l[j-1];
      l[j]%=dr;
    }
  }
  for(i=0;i<k;i++) mm+=l[i];
  printf("%ld",mm);
  return(0);
}