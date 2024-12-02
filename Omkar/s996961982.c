#include <stdio.h>
int main()
{
  int W,H,N,i;
  int X[1000];
  int Y[100];
  int A[100];

  scanf("%d %d %d",&W,&H,&N);

  for(i=1;i<=N;i++)
  {
    scanf("%d %d %d",&X[i],&Y[i],&A[i]);
  }

  int x1,x2,y1,y2,sum;
  x1=0;
  x2=W;
  y1=0;
  y2=H;

  for(i=1;i<=N;i++)
  {
    switch (A[i])
    {
      case 1:
        x1=X[i];
        break;

      case 2:
        x2=X[i];
        break;

      case 3:
        y1=Y[i];
        break;

      case 4:
        y2=Y[i];
        break;
    }
  }
  sum=(x2-x1)*(y2-y1);
  printf("%d\n",sum);

  return 0;

}
