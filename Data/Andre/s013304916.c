#include <stdio.h>
double zenka(double q)
{
 double x=q/2;
   while(x*x*x-q>=0.00001*q || x*x*x-q<=-0.00001*q)
   {
       x=x-((x*x*x)-q)/(3*x*x);
   }
   return x;
}
int main(void)
{
   int q;

   while(1)
   {
       scanf("%d",&q);
       if(q==-1) break;
       else
       {
           printf("%.7f\n",zenka(q));
       }
   }
   return 0;
}
