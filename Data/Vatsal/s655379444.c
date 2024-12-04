#include <stdio.h>

char line[100];
int n, k, a;

int main() {
    fgets(line, sizeof(line), stdin);
    sscanf(line,"%d %d", &n, &k);

    a = n % k;
    printf("%d", a);
    return(0);
}