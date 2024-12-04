#include <stdio.h>
#include <math.h>
#define swap(a,b) a^=b^=a^=b

int main(){
	
	int a, b, c, d, e, f, B, C;
	double A, D, E;
	
	while(scanf("%d %d %d %d %d %d", &a, &b, &c, &d, &e, &f) != EOF){
		B = c*e-b*f;
		C = -d*c+a*f;
		A = 1/(a*e*1.0-b*d*1.0);
		D = A*(B*1.0);
		E = A*(C*1.0);
		if (D == -0.000000) D = 0.000000;
        if (E == -0.000000) E = 0.000000;
		printf("%.3f %.3f\n", D, E);
	}
	return 0;
}