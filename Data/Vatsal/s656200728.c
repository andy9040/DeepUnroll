#include<stdio.h>
#include <math.h>
int main()
{
    int N,K,;

    while ((N<0||10^9<N)||(K<2||10<K))
    {
        scanf("%d %d\n",N,K);
    }

    printf("%d\n",logN(K));

    return 0;
}