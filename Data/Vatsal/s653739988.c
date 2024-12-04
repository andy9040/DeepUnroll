// ABC 147-D
// 2019.12.23 bal4u

#include <stdio.h>
#include <ctype.h>

typedef long long ll;

#define gc() getchar_unlocked()

ll in() {   // 非負整数の入力
	ll n = 0; int c;
	do c = gc();
	while (isspace(c));
	do n = 10 * n + (c & 0xf); while ((c = gc()) >= '0');
	return n;
}

#define M 1000000007
int N;
ll A[300005];

int main()
{
	int i, b, n;
	ll ans, a;
	
	N = (int)in();
	for (i = 0; i < N; ++i) 	A[i] = in();

	ans = 0;
	b = 61; while (b--) {
		n = 0, i = N; while (i--) {
			if ((A[i] >> b) & 1) ++n;
		}
		a = (ll)n * (N-n) % M;
		ans = (ans + (a << b)) % M;
	}
	printf("%d\n", (int)ans);
	return 0;
}
