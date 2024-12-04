#include<stdio.h>
#include<math.h>

int main(void)
{
  double a, b, c, C;
  double s,l, h,d;

  scanf("%lf %lf %lf",&a,&b,&C);

  d = C / 180 * M_PI;
  s = a * b * sin(d) / 2;
  c = sqrt(a * a  + b * b - 2 * a * b * cos(d));
  l = a + b + c;
  h = b * sin(d);

  printf("%f\n%f\n%f\n",s,l,h);

  return 0;
}