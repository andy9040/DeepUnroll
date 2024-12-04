#include<stdio.h>
#include<stdlib.h>
#define ll long long
int cmp(const void *a,const void *b){return *(long long*)a-*(long long*)b;}
ll gcd(ll a,ll b){
    ll r = a % b;
    while(r > 0){
        a = b;
        b = r;
        r = a % b;
    }
    return b;
}
ll max(ll a,ll b){return a>b?a:b;}
int main(){
    ll n;
    scanf("%lld",&n);
    ll a[n];
    for (ll i = 0; i < n; i++)
        scanf("%lld",&a[i]);
    if (n == 2){
        printf("%lld\n",max(a[0],a[1]));
        return 0;
    }
    qsort(a,n,sizeof(long long),cmp);
    ll p = gcd(a[0],a[1]);
    ll q = gcd(a[0],a[2]);
    ll r = gcd(a[1],a[2]);
    printf("%lld\n",max(r,max(p,q)));
    return 0;
}