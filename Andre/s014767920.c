#include <stdio.h>
#include <math.h>

int main(void)
{
	float  x1, x2, y1, y2;
	double dis;
	
	scanf("%1f %1f %1f %1f", &x1, &y1, &x2, &y2);
	
	dis = ((x1 - x2) * (x1 - x2)) + ((y1 - y2) * (y1 - y2));
	
	printf("%f\n", sqrt(dis));
	
	return (0);
}