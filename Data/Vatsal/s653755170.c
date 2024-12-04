#include<stdio.h>
int main(void){
  int N;
  int n;
  scanf(%d,&N);
  if((N%2)==0){
    n=(N/2)-1;
  } 
  else{
    n=((N+1)/2)-1;
  }
  printf("%d",n);
  return 0;
}
    