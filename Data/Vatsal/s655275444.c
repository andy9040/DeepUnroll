#include<stdio.h>
 int main()
 {
  int n,a;
  scanf("%d",&n);
  a=1000-(n%1000);
  printf("%d",a);
  return 0;
 }