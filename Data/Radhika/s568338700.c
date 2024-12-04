#include <stdio.h>
#include <string.h>
#define MAX 50

int main(void) {
    int i, n, t, p, ary[MAX] = {};
    while(scanf("%d %d", &n, &p), n || p) {
        memset(ary, 0, sizeof(ary));
        for(i = ~-n, t = p; ary[i = -~i % n] != p;) {
            t ? t--, ary[i]++ : (t += ary[i], ary[i] = 0);
        }
        printf("%d\n", i);
    }
    return 0;
}