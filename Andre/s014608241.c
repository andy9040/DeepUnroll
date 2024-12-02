#include <stdio.h>
 
int main(void)
{
  int first,second,third;
  scanf("%d,%d,%d",&first,&second,&third);
  if(first==5&&second==7&&third==5)printf("YES");
  if(first=!5||second=!7||third=!5)printf("NO");
  return 0;
}