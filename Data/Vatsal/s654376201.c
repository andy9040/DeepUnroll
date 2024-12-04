#include <stdio.h>

int main(void){
  int N,a;
  scanf("%d",&N);
  if(N%1000 == 0 ){
  a = N/1000;
  }  else{
a = N/1000 + 1;
}
  int b = 1000*a-N;


   printf("%d\n",b);
}
