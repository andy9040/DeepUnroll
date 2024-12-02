#include <stdio.h>
#include <math.h>

int xx (int x, int y)
{
	int xxx;
	xxx = x - y;
	
	return xxx*xxx;
}

int main (void) {
    int x1, x2, y1, y2, z1, z2;
	int i, j;
	double d;
	
	scanf("%d", &i);
	
	for (j=0; j<i; j++) {
		scanf("%d%d%d%d%d", &x1, &y1, &z1, &x2, &y2, &z2);
		d = sqrt(xx(x1, x2) + xx(y1, y2) + xx(z1, z2));
		printf("%f\n", d);
	}
	
    return 0;
}