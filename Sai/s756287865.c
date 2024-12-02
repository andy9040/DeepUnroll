#include<stdio.h>

int main(void){
  int n,x,count;
  while(scanf("%d",&n),n){
    count=0;
    for(;n>0;n--)for(x=n;x%5==0;){x=x/5;count++;}
    printf("%d\n",count);
  }
  return 0;
}