#include<stdio.h>
int main(void){
  int S,F;
  scanf("%d %d",&S,&F);
  if(S>=F){
     printf("safe");
  }
  else{
    printf("unsafe");
  }
  return 0;
}
