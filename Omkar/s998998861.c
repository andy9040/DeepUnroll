#include "stdio.h"

int main(void)
{
    int s;
    int w;

    scanf("%d",&s);
    scanf("%d",&w);

    if(s<=w)
    {
        printf("unsafe");
    }
    else
    {
        printf("safe");
    }
    return 0;
}