#include <stdio.h>

int main()
{
    int n,d;
    scanf("%d %d",&n,&d);
    printf("%d",n % (d * 2 + 1) == 0 ? n / (d * 2 + 1) : n / (d * 2 + 1) + 1);
}
