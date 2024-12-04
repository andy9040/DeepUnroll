#include<stdio.h>

int main(void){
 int N,K;
  scanf("%d %d",&N,&K);
  if(N%K==0){
    printf("0");
  }else{
    printf("1");
  }
  return 0;
}