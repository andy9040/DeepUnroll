#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <math.h>
int main(){
	float x1,x2,y1,y2;
	double a = 0.0;
	double j ,k;
	x1 = 0;
	x2 = 0;
	y1 = 0;
	y2 = 0;
	scanf("%f %f %f %f",&x1,&y1,&x2,&y2);
	if(x1 == x2){
		a = fabs(y1 - y2);
	}else if(y1 == y2){
		a = fabs(x1 - x2);
	}else{
		k = fabs(y1 - y2);
		j = fabs(x1 - x2);
		printf("%f",j);
		a = sqrt(((k*k) + (j*j)));
	}
	printf("%f\n",a);
	return 0;
}
 
 