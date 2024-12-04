#include<stdio.h>
int main()
{
    int n;
    scanf("%d",&n);
    while(n>1000)
    {
        n= n-1000;
    }
    int m = 1000-n;
    printf("%d",m);
}