#include<stdio.h>

int main()
{
  int a;
  int b[3];
  int ans;
  
  scanf("%d", &a);
  
  b[0] = a/100;
  b[1] = a%100/10;
  b[2] = a%10;
  
  ans = b[0] + b[1] + b[2];

  printf("%d", ans);
  return(0);
}