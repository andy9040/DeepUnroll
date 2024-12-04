#include<stdio.h>
int main()
{
    int n,b;
    scanf("%d %d",&n,&b);
    int A[n],i,j,k=0;
    for(i=0;i<n;i++)
    {
        scanf("%d",&A[i]);
        k=k+A[i];
    }
    if(k/(4*b)<=A[b-1])
        printf("Yes\n");
    else printf("No\n");
    return 0;
}
