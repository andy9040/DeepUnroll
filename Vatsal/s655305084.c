#include <stdio.h>

int main( void ) {
	int n, sum;

	for ( ; scanf( "%d", &n ), n; printf( "%d\n", sum ) )
		for ( sum = 0; n /= 5; sum += n );

	return 0;
}