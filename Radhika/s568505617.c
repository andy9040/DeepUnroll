#include<stdio.h>

int main(){
  int D,N;
  
  if(scanf("%d%d",&N,&D) == 2){
      int i=N/2*D;
  
  if(N%D != 0)i++;
  
  printf("%d",i);
  }
  
  return 0;
}