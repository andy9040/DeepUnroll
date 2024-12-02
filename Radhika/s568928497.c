#include<stdio.h>
int main(){
  int n,i,count=0;
  scanf("%d",&n);
  int p[n];
  for(i=0;i<n;i++)
    scanf("%d",&p[i]);
  for(i=1;i<n-1;i++){
    if((p[i]-p[i-1])*(p[i]-p[i+1])<0)
      count++;
  }
  printf("%d\n",count);
  return 0;
}
