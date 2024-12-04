#include <stdio.h>
#include <stdlib.h>
#define MOD 1000000007
#define MAX 1000000000
typedef long long ll;

ll C(ll n, int k) {
    ll a = 1; // = n!
    ll b = 1; // = (n-k)!
    ll c = 1; // = k!

    for(ll i = 0; i < n; i++) a = (a * (n - i)) % MOD;
    for(ll i = 0; i < n - k; i++) b = (b * (n - k - i)) % MOD;
    for(int i = 0; i < k; i++) c = (c * (k - i)) % MOD;

    ll bc = (b * c) % MOD;

    return (a / bc) % MOD;
}

int main(void) {
    ll n; int a, b, ans = 0;
    scanf("%lld %d %d", &n, &a, &b);

    for(ll i = 1; i <= n; i++) {
        if(i == a || i == b) continue;
        ans += C(n, i);
    }
    printf("%d\n",ans);
}
