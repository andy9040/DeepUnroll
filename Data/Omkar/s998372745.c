#include <stdio.h>
int main(void){
  int a,b;
  scanf("%d",&a);
  scanf("%d",&b);
  if(a>b){
    printf("safe");
  }
  else{
    printf("unsafe");
  }
  return 0;
}