#include<stdio.h>

int main()
{
   char a[100000];
   int i,j,x,y;
   scanf("%s",&a[0]);
   i=0,j=0,x=0,y=0;
   while(a[i] !="/0")
   {
       if(a[i] !='0' || a[i] !='1')
             scanf("%c",&a[i]);
       i++;
   }
   while(a[j] !="/0")
   {
          if(a[j] == a[j+1] && a[j] == '0')
          {
               a[j]='1';
               x++;
           }
          if(a[j] == a[j+1] && a[j] == '1')
          {
               a[j]='0';
               y++;
          }
        j++;
   }
   if(i == 1)
        printf("0/n");
   else
   {
        if(x>=y)
              printf("%d",y);
        else
              printf("%d",x);
    }
   return 0;
}