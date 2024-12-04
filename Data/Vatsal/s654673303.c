#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>
#include<math.h>
#include<ctype.h>

typedef long long ll;

ll gcd(ll a, ll b) { if (b == 0) return a; return gcd(b, a % b); }

ll lcm(ll a, ll b) { return a / gcd(a, b) * b; }

ll max(ll a, ll b) { return (a > b) ? a : b; }

ll min(ll a, ll b) { return (a < b) ? a : b; }

ll asc(const void* a, const void* b) { return *(ll*)a - *(ll*)b; }

ll dsc(const void* a, const void* b) { return *(ll*)b - *(ll*)a; }

bool flag;

int main() {
	ll n, a[100000];
	scanf("%lld", &n);
	for (ll i = 0; i < n; i++) scanf("%lld", &a[i]);
	ll gcdA = a[0], gcdB = a[1];
	for (ll i = 1; i < n; i++) {
		if (!flag&&(gcd(gcdA, a[i]) == 1)) { flag = true; }
		else gcdA = gcd(gcdA, a[i]);
		gcdB = gcd(gcdB, a[i]);
	}
	ll gcdC = a[0] / gcdA;
	if (flag) { printf("%lld", max(gcdA, gcdB)); return 0; }
	else {
      	flag=false;
      	gcdB=a[1]/gcdA;
		for (int i = 1; i < n; i++){
			a[i] /= gcdA;
			if(!flag&&(gcd(gcdC,a[i])==1)) flag=true;
          	else gcdC = gcd(gcdC, a[i]);
          	gcdB = gcd(gcdB, a[i]);
		}
		printf("%lld", max(gcdC * gcdA, gcdB*gcdA));
    }
	
	return 0;
}