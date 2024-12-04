#include <stdio.h>
#include <math.h>

void main()
{
  int x, h=0;
  scanf("%d", &x);
  while(x>=5)
  {
    if(x>=500)
    {
      h=h+1000;
      x=x-500;
    }
    if(x>=5)
    {
      h=h+5;
      x-=5;
    }
  }
  printf("%d", h);
}