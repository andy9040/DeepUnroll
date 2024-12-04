#include <stdio.h>

int main(){
	long long A, B, C, K, ans=0;

	scanf("%lld %lld %lld %lld", &A, &B, &C, &K);

	if(A<=K && K>0){
		ans += A;
		K -= A;
	}
	else if(A>K && K>0){
		ans += K;
		K = 0;
	}

	if(B<=K && K>0){
		K -= B;
	}
	else if(B>K && K>0){
		K = 0;
	}

	if(K>0){
		ans -= K;
	}

	printf("%lld", ans);

	return 0;
}
