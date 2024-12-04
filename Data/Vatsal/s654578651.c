#include <stdio.h>
#include <math.h>
#define PI acos(-1)

int main(void)
{
    double rad,a,b,c,s,l,h;
    
    scanf("%lf%lf%lf",&a,&b,&c);
    rad=c*PI/180;
    
    h=a*b/2*sin(c);
    s=a*h/2;
    l=a+b+sqrt(pow(a,2)+pow(b,2)-2*a*b*cos(c));
    
    printf("%f\n%f\n%f\n",s,l,h);
    return 0;
}
