#include<stdio.h>

double rounding(double value)
{
	if(value - (double)(int)value < 0.5)
	{
		return (double)(int)value;
	}
	else
	{
		return (double)(int)(value + 0.9);
	}
}

double determinant(double a, double b, double c, double d)
{
	return (a * d) - (b * c);
}

int main(void)
{
	double a, b, c, d, e, f;
	double A, d1, d2;
	double x, y, X, Y;
	
	scanf("%lf %lf %lf %lf %lf %lf", &a, &b, &c, &d, &e, &f);

	A = determinant(a, b, d, e);
	d1 = determinant(c, b, f, e);
	d2 = determinant(a, c, d, f);

	x = d1 / A;
	y = d2 / A;

	X = x * 1000.0;
	Y = y * 1000.0;

	x = rounding(X) / 1000.0;
	y = rounding(Y) / 1000.0;

	printf("%.3f %.3f", x, y);

	return 0;
}