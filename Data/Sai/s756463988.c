#include<stdio.h>

int main(void)
{
  int W,H,N,x,y,a;
  int ansx = 0,ansy = 0;
  scanf("%d%d%d",&W,&H,&N);
  
  for(int i = 0;i < N;i++)
  {
    scanf("%d%d%d",&x,&y,&a);
    switch(a)
    {
      case 1:
        if(ansx < x){ansx = x;}
        break;
      case 2:
        if(x < W){W = x;}
        break;
      case 3:
        if(ansy < y){ansy = y;}
        break;
      case 4:
        if(y < H){H = y;}
        break;
    }
  }
  
  printf("%d",(W - ansx) * (H - ansy));
  
  return 0;
}