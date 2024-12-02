#include<stdio.h>

int main()
{
    int a,i,x;
    scanf("%d",&a);

    if(a%10 == 1)
    {
        i++;
    }

    x = a/10;
    if(x%10 == 1)
    {
        i++;
    }

    x = x/10;
    if(x%10 == 1)
    {
        i++;
    }

    printf("%d/n",i);
}