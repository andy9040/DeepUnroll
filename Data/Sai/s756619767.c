#include <stdio.h>
#include <stdlib.h>
#include <stdlib.h>


long gcd (long a, long b) {
	ldiv_t t = ldiv (a,b);
	long c = t.rem;
	if (c==0)
		return b;
	return gcd (b, c);
}

int main () {
	int n;
	long x, d;

	scanf ("%d %ld", &n, &x);
	scanf ("%ld", &d);
	d = labs (d - x);
	for (int i=1; i<n; i++) {
		long tmp;
		printf ("%d\n", i);
		scanf ("%ld", &tmp);
		d = gcd (labs (tmp-x), d);
	}
	printf ("%ld\n", d);
	return 0;
}
