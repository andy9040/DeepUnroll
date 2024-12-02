#include <stdio.h>

#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

#define N 200010
#define MAX 1000000000000000000

#include <stdio.h>

int main (void) {
    int s, w;

    scanf("%d %d", &s, &w);

    if (w >= s) puts("unsafe");
    else puts("safe");

    return 0;
}

