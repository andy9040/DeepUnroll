#include <stdio.h>

int main()
{
   int h,w,l1,l2;
   scanf("%d%d",&h,&w);
   l1=(h/2)*(w/2);
   l2=(h-h/2)*(w-w/2);
   printf("%d",l1+l2);

    return 0;
}
