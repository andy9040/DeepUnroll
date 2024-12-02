#include<stdio.h>
#include<stdlib.h>
int main()
{
    int n,now=1;
    scanf("%d",&n);
    while(now<n)
    now*=1000;
    printf("%d",now-n);
}
