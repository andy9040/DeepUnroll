#include <stdio.h>

int main(){
	double a,b,c,d,e,f, x,y,dd;
	while(scanf("%lf %lf %lf %lf %lf %lf",&a,&b,&c,&d,&e,&f)>0){
		dd = (a*e-b*d);
		x=(c*e-b*f)/dd;
		y=(a*f-c*d)/dd;
		//if(x==0)x=0;
		printf("%.3f %.3f\n",x,y);
	}
	return 0;
}