#include<stdio.h>
main(){
  int x;
  while(1){
    scanf("%d",&x);
    if(x==0) break;
    printf("%d\n",x);
  }
  return 0;
}