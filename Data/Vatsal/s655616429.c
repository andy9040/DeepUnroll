#include <stdio.h>
#include <math.h>
 
int main()
{
  int a,b,c;
  double S,L;
  scanf("%d",&a);
  scanf("%d",&b);
  scanf("%d",&c);
  S=a*b*sin(c*M_PI/180)/2;
  L=sqrt(pow(a,2)+pow(b,2)-2*a*b*cos(c*M_PI/180))+a+b;
  printf("%lf\n",S);
  printf("%lf\n",L);
  printf("%lf\n",2*S/a);
  return 0;
}
