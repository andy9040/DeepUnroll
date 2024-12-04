#include <stdio.h>

int main(void)
{
    int d, l;
    scanf("%d %d", &d, &l);
    printf("%d\n", d / l + d % l);
    return 0;
}