#include <stdio.h>
#include <math.h>

int main(){
	int a,b,c;
	double s,l,h,rad;
	scanf("%d %d %d",&a,&b,&c);
	rad=atan(1)*c/180.;
	s=0.5*a*b*sin(rad);
	l=a+b+(a*a+b*b-2*a*b*cos(rad));
	h=2*s/a;
	printf("%f %f %f\n",s,l,h);
	return 0;
}