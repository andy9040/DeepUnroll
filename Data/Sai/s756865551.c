

#include <stdio.h>
long long a[300010];
int main()
{
    int n,i,j;
    long long sum=0;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%lld",&a[i]);

    }
    for(i=0;i<n-1;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if((a[i]^a[j])>=1000000007)
                sum +=(a[i]^a[j])%1000000007;
            else
                sum +=(a[i]^a[j]);
            if(sum>=1000000007)
                sum=sum%1000000007;
        }
    }
    printf("%lld\n",sum);

}
