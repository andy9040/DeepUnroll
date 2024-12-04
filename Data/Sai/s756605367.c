#include <stdio.h>

int main()
{
    int A, B;
    scanf("%d%d", &A, &B);
    if(A < 2 * B){
        printf("%d\n", 0);
    } else {
        printf("%d\n", A - 2 * B);
    }
    return 0;
}
