#include<stdio.h>

int main(){
  int ans[10];
  int stp[10];
  int car;
  int i,j;

  for(i=0;i<10;i++){
    ans[i]=0;
    stp[i]=0;
  }

  i=0;
  j=0;
  while(scanf("%d",&car)!=EOF){
    if(car==0){
      ans[j]=stp[i-1];
      j++;
      stp[i-1]=0;
      i--;
    }
    else{
      stp[i]=car;
      i++;
    }
  }

  for(i=0;i<j;i++){
    printf("%d\n",ans[i]);
  }

  return 0;
}