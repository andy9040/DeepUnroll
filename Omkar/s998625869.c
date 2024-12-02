#include<stdio.h>
int main(){
  int n, a[100], i,max=0,min=1000;
  scanf("%d",&n);
  for(i=0; i<=n; i++){
    scanf("%d",&a[i]);
    if(a[i]>max){
      max=a[i];
    }
    if(a[i]<min){
      min=a[i];
    }
  }
  printf("%d\n",max-min);
  return 0;
}
