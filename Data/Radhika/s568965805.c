#include<stdio.h>
#include<math.h>

int main(void)
{
	int a;
	int b;
	int C;
	double S;
	double L;
	double h;
	double pi;
	double rad;
	
	pi = 3.1415926535;
	scanf("%d %d %d", &a, &b, &C);
	if(C > 180){
		while(1){
			C -= 180;
			if(C <= 180){
				break;
			}
		}
	}
	rad = C * pi / 180;
	if(C >= 0){ 
		if(C > 90){
			C = 180 - C;
		}
		if(C == 90){
			h = b;
		}
		else if(C < 90){
			h = a * sin(rad);
		}
	}
	S = h * a / 2;
	L = a + b + sqrt((b * sin(rad)) * (b * sin(rad)) + ((a - b * cos(rad)) * (a - b * cos(rad))));
	
	printf("%.8f\n", S);
	printf("%.8f\n", L);
	printf("%.8f\n", h);
	
	return (0);
}