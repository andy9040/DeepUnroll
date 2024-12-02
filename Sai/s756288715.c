#include <stdio.h>
#include <math.h>
 
int main(int argc, const char * argv[]) {
    double a, b, d, C, S, L, h;
     
    scanf("%lf %lf %lf",&a, &b, &C);
     
    C = C * M_PI / 180;
     
    h = b * sin(C);
     
    S = a * h / 2;
     
    d = sqrt(a * a + b * b - 2 * a * b * cos(C));
     
    L = a + b + d;
     
    printf("%f\n%f\n%f\n",S, L, h);
     
     
    return 0;
}