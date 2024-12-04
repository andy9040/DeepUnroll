#include <stdio.h>

int main(){
	int a,b,c,d,e,f;
	double tmp,b2,c2,f2;
	double x,y;

	while(scanf("%d %d %d %d %d %d",&a,&b,&c,&d,&e,&f) != EOF){
		tmp = (a*1.0)/d;
		b2 = b*1.0-e*1.0*tmp;
		c2 = c*1.0-f*1.0*tmp;
		y = c2 / b2;
		f2 = f-e*y;
		x = f2 / d;
		if((int)(x*1000.0) == 0){
			x = 0.0;
		}else if((int)(y*1000.0) == 0){
			y = 0.0;
		}
		printf("%.3f %.3f\n",x,y);
	}

	return 0;
}