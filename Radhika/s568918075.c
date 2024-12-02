#include <stdio.h>
#define MAX 100010

long max(long a[], long n)
{
	long i, max = 0;
	for (i = 0; i < n; i++){
		if (a[i] >= max) max = a[i];
	}
	return max;
}
long countSumb(long a[],long b[], long H, long n,long *tmp)
{
	long i = 0, cnt = 0; *tmp = 0;
	long maxa = max(a, n);
	//printf("maxa=%ld\n", maxa);
	while (i < n) { 
		if (maxa <= b[i]) { *tmp += b[i]; cnt++; }
		i++;
		if (*tmp >= H) break; 
	}
	//printf("cnt:%ld\n", cnt);
	//printf("sum:%ld\n", *tmp);
	return cnt;
}
int main(void)
{
	long N, H;
	long a[MAX], b[MAX];
	scanf("%ld%ld", &N, &H);
	for (long i = 0; i < N; i++)
		scanf("%ld%ld", &a[i], &b[i]);
	long sumofB, nB;
	nB = countSumb(a,b,H,N,&sumofB);
	long suma=0,maxa=0;
	if (sumofB < H) {
		//printf("sum:%ld\n", sumofB);
		maxa = max(a, N);
		long less = H - sumofB;
		//printf("les:%ld\n", less);
		if (less % maxa != 0) suma = less / maxa + 1;
		else suma = less / maxa;
		//printf("..A:%ld\n", suma);
	}
	printf("%ld\n", suma + nB);
	return 0;
}