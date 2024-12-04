#include <stdio.h>

int main(){
  int n,ans=0;
  scanf("%d",&n);
  int p[n+1];
  for(int i=1;i<=n;i++){
    scanf("%d",&p[i]);
  }
  
  for(int i=2;i<=n-1;i++){
    if((p[i-1]<p[i] && p[i]<=p[i+1]) || (p[i-1]>=p[i] && p[i]>p[i+1])){
      ans+=1;
    }
  }
  
  printf("%d",ans);
  return 0;
}