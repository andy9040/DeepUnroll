#include<stdio.h>
int main()
{
    int n, k, c=0, result;
    scanf("%d %d", &n , &k);
    up: result=n/k;
    if(result>0)
    {
        c++;
        n=result;
        goto up;
    }
    else if (result==0)
    {
        printf("%d", c+1);
        return 0;
    }
}
