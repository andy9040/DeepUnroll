#include <stdio.h>

#define LENGTH 256

int conper(int n, int a, int b) {
    if (b < n * a) {
        return b;
    } else {
        return n * a;
    }
}

int main(void) {
    char input[LENGTH];
    int n, a, b;
    int r;
    if (scanf("%d %d %d", &n, &a, &b) == 1);
    r = conper(n, a, b);
    printf("%d", r);
    return 0;
}