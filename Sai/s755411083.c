#include <stdio.h>
#define _USE_MATH_DEFINES
#include <math.h>

int main(){
    int a, b, angle;
    double s, l, h;

    scanf("%d %d %d", &a, &b, &angle);
    
    h=b*sin(angle*M_PI/180.0);
    s=a*h/2;
    l=a+b+sqrt((a*a+b*b-2*a*b*cos(angle*M_PI/180.0)));
    printf("%f\n", s);
    printf("%f\n", l);
    printf("%f\n", h);

    return 0;
}
