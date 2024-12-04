#include<stdio.h>

int main(void){
  int a,b,c;
  scanf("%d %d",&a,&b);
  c=a+b;
  if(c<24)
    printf("%d\n",c);
  else
    printf("%d\n",c%24);
  return 0;
}