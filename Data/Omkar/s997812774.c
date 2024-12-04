#include<stdio.h>

int main()
{
  int n;
  int a;
  scanf("%d",&n);
  a=1000-n%1000;
  if(a==1000) a=0;
  printf("%d",a);
  return 0;
}
