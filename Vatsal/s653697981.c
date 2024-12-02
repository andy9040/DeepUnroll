#include <stdio.h>
#include <math.h>
typedef long long ll;
#define mod 1e9+7

ll fact(ll n){
    ll ans = n;
    for(ll i = n-1; i > 1; i--){
        ans = ans*i;
    }
    return ans;
}

ll combination(ll n,ll r){
    

    if(n < 0||r<0||n<r){
        return 0;
    }

    if(n==r||!r){
        return 1;
    }

    /*if(dp[n][r]){
        return combination(n,r);
    }*/

    
    
    return combination(n-1,r)%(ll)mod+combination(n-1,r-1)%(ll)mod;
}

int main(void){
    int n,a,b;
    scanf("%d %d %d",&n,&a,&b);

    

    ll temp = ((ll)pow(2,n))%(ll)mod-combination(n,a)-combination(n,b);

    printf("%lld\n",temp);

    return 0;
}