#include <stdio.h>

int main(void)
{
	float x,y,a,b,c,d,e,f;
	while (scanf("%f %f %f %f %f %f %f", &a, &b, &c, &d, &e, &f) != -1){
		x=(c/b-f/e)/(a/b-d/e);
		y=(c-a*x)/b;
		if (x>=0){
			x=x+0.0005;
		} else x=x-0.0005;
		if (y>=0){
			y=y+0.0005;
		} else y=y-0.0005;
		printf("%.3f %.3f\n", x, y);
	}
	return 0;
}