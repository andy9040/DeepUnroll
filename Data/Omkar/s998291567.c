#include<stdio.h>
#include<math.h>

#define pi 3.14159265

double s(double a, double b, double ct){
   return ( a * b ) * sin( ct * pi / 180.0) / 2;
}
double l(double a, double b, double ct){
    double
    c = sqrt( a * a + b * b - 2 * a * b * cos(ct * pi / 180.0));
    return a + b + c;
}
double H(double a, double b, double ct){
    return s(a,b,ct) * 2 / a;
}

int main(){
    double a, b, ct;
    scanf("%lf%lf%lf", &a, &b, &ct);
    printf("%f\n%f\n%f\n", s(a,b,ct), l(a,b,ct), H(a,b,ct));
    return 0;
}