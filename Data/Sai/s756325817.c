#include <stdio.h>

int main( void ) {
	int i, n, p, now, have[ 50 ], rest;

	for ( ; scanf( "%d %d", &n, &p ), rest = p; printf( "%d\n", now ) ) {
		for ( i = 0; i < 50; i++ )
			have[ i ] = 0;

		for ( now = 0; ; now = ( now + 1 ) % n ) {
			if ( rest == 1 && have[ now ] == p - 1 )
				break;

			if ( rest == 0 ) {
				rest = have[ now ];
				have[ now ] = 0;
			} else {
				rest--;
				have[ now ]++;
			}
		}
	}

	return 0;
}