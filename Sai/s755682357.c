#include<stdio.h>
int main(){
  int a,b;
  scanf("%d",&a);
  scanf("%d",&b);
  if(a>=2*b){
    printf("%d",a-2*b);
  else{
    printf("%d",0);
  }
  return 0;
}