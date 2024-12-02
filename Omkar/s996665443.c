#include<stdio.h>
int main(void){
  int n,m;
  int a[1000];
  int i;
  int ans=0;
  int hyo=0;
  scanf("%d%d",&n,&m);
  for(i=0;i<n;i++){
    scanf("%d",&a[i]);
    hyo+=a[i];
  }
  for(i=0;i<n;i++){
    if(a[i]>=hyo/4/m)
      ans+=1;
  }
  if(ans>=m)
    printf("Yes");
  else
    printf("No");
  return 0;
}