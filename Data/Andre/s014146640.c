#include <stdio.h>

int main(void)
{
    int N, A, B;
    scanf("%d %d %d", &N, &A, &B);

    printf("%d\n", A*N < B ? A*N : B);

    return 0;
}