#include <stdio.h>
typedef long long int ll;
int main()
{
    ll a[10000001],n,sum=0;
    scanf("%lld",&n);
    for(int i=1;i<10000001;i++)a[i]=1;
    for(ll i=2;i<10000001;i++)
    {
        if(a[i]==1)
        {
            for(ll j=i;j<10000001;j+=i)
            {
                a[j]=(a[j/i]+1);
            }
        }
    }
    for(ll i=1;i<=n;i++)
    sum+=(i*a[i]);
    printf("%lld",sum);
}
