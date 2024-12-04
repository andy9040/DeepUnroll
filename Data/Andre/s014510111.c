#include <stdio.h>

int main()
{
  long cnt;
  long ans=0;
  
  scanf("%lu",&cnt);
  
  ans+=cnt/500*1000;
  cnt%=500;
  ans+=cnt;
  printf("%lu",ans);
}