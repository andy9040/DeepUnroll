#include<stdio.h>
int main(){
  while(1){
  int n;
  scanf("%d",&n);
  if(n<=0 || n >100){
    break;
  }
  int a[n];
  int temp;
  int i, j;
  int count=0;
  for(i=0; i<n; i++){
  scanf("%d",&a[i]);
  if(a[i]<=0 || a[i] >1000000){
    return 0;
  }
  }
    for(i=0; i<n-1; i++){
    for(j=i+1; j<n; j++){
      if(a[j]<a[i]){
        temp=a[j];
        a[j]=a[i];
        a[i]=temp;
        count += 1;
      }    
    }
    }
    printf("%d\n",count);
  }
  return 0;
}