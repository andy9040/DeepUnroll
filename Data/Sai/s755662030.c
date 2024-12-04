#include <stdio.h>
int main()
{
    int M,N,A[100],i,c=0,s=0;
    scanf("%d%d",&N,&M);
    for(i=0;i<N;i++)
    {
        scanf("%d",&A[i]);
        s+=A[i];
    }
    i=0;
    while(i<N)
    {
        if(A[i]>=(s/(4*M)))
        {c++;}
        i++;
    }
    if(c>=M)
    printf("\nYes");
    else
    printf("\nNo");
    return 0;
}
