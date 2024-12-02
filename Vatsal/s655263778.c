#include<stdio.h>
#include<math.h>
int main()
{

   double S,L,h,rad,a,b,C;

    scanf("%lf %lf %lf",&a,&b,&C);
     rad=C*M_PI/180.0;
    S=(1/2.0)*a*b*sin(rad);
    L=a+b+sqrt((a*a)+(b*b)-(2.0*a*b*cos(rad)));
    h=(2.0*S)/a;
    printf("%lf\n%lf\n%lf",S,L,h);
    return 0;
}
