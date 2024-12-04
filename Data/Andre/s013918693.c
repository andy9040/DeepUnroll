#include<stdio.h>

int main(void){
  int n,x,count5;
  
  while(scanf("%d",&n),n){
    count5=0;
    for(;n>0;n--){
      x=n;while(x%5==0){x=x/5;count5++;}
    }
    printf("%d\n",count5);
  }
  return 0;
}