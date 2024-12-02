#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define df 0


int main(){
  int n,d;
  scanf("%d",&n,&d);
  d=2*d+1;

  printf("%d",(n-1)/d+1);
  return 0;
}


/// confirm df==0 ///