#include <stdio.h>
#include <string.h>

int main()
{
  int a,b,c;
  scanf("%d",&a);
  scanf("%d",&c);
  scanf("%d",&b);

  if( a<b&&b<c)
    printf("Yes\n");
  else if(a>b&&b>c)
    printf("Yes\n");
  else
    printf("No\n");
  return 0;
}
