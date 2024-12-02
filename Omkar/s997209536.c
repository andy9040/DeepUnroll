#include <stdio.h>
int main (void)
{
    int A,B;
    scanf("%d%d",&A,&B);
    if (A>2*B)
    {
        printf("%d",A-2*B);
    }
    else
    {
        printf("0");
    }
    return 0;
}
