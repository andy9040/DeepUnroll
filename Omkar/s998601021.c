#include<stdio.h>
int main(void){
	int a,b,c,d,e,f,i;
	double x,y;
	for(;;){
		scanf("%d %d %d %d %d %d",&a,&b,&c,&d,&e,&f);
		y=(c*d-a*f)/(b*d-a*e);
		x=(c*e-f*b)/(a*e-b*d);
		printf("%.3f %.3f\n",x,y);
	}
	return 0;
}
