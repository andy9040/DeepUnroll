#include <stdio.h>

int main( void ) {
	int i, n, p, have[ 50 ], r;

	for ( ; scanf( "%d %d", &n, &p ), r = p; printf( "%d\n", i ) ) {
		for ( i = 0; i < 50; i++ )
			have[ i ] = 0;

		for ( i = 0; ; i = ( i + 1 ) % n ) {
			if ( r ) {
				r--;
				have[ i ]++;
			} else {
				r = have[ i ];
				have[ i ] = 0;				
			}

			if ( r == p )
				break;
		}
	}

	return 0;
}