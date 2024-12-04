#include<stdio.h>

int main(){
  int n;
  scanf("%d",&n);
  int a[n+1];
  for(int i=1;i<=n;i++)scanf("%d",&a[i]);
  
  int ans=0;
  
  for(int i=1;i<=n;i++){
    if(i%2==1 && a[i]%2==1)ans+=1;
  }
  
  printf("%d",ans);
  return 0;
}