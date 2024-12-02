#include<stdio.h>

int main()
{
    int n,a,b;
    scanf("%d%d%d",&n,&a,&b);
    if(n*a<b)
        printf("%d",n*a);
    else printf("%d",b);
    return 0;
}
