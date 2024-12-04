#include <stdio.h>
#define lop(i, n) for(i=0; i<n; i++)

int main()
{
	int N, M, i, sum=0, cnt=0;
	int A[1000];
	
	scanf("%d %d", &N, &M);
	lop(i, N){
		scanf("%d", &A[i]);
		sum+=A[i];
	}
	
	float rin=sum/(4*M);
	
	lop(i, N){
		if(rin<=A[i])cnt++;
	}
	
	if(cnt>=M){ printf("Yes"); }
	else { printf("No"); }
	
return 0;
}