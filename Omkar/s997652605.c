#include<stdio.h>
int main(void)
{
  int n;
  scanf("%d",&n);
  n %= 1000;
  if(n == 0) n = 1000;
  printf("%d",1000 - n);
  return 0;
}
