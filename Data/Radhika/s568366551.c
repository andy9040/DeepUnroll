#include<stdio.h>
int main()
{
    int count=0,n,k;
    scanf("%d%d",&n,&k);
    while(n!=0)
    {
        n=n/k;
        count++;
    }
    printf("%d",count);
    return 0;
}
