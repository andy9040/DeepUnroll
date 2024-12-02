#include <stdio.h>
#include <stdlib.h>
#define MAX(x,y) x>y?x:y

int cmpfunc (const void * a, const void * b) {
   return ( *(int*)a - *(int*)b );
}

int main(){
	long N,*arr;
	scanf("%ld",&N);
	arr=malloc(sizeof(long)*N);
	for(long i=0;i<N;i++) scanf("%ld",&arr[i]);
	for(long i=0;i<N;i++)
	{
		long *Arr;
		Arr=malloc(sizeof(long)*(N-1));
		for(long j=0;j<N;j++)
		{
			Arr[j]=arr[j<i?j:j+1];
		}
		qsort(arr,N,sizeof(long),cmpfunc);
		printf("%ld\n",Arr[N/2-1]);
		free(Arr);
	}	
	free(arr);
	return 0;
}