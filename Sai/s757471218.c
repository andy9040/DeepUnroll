
#include <stdio.h>


main(){
	int N,l,r,i;
	int sum = 0;
	scanf("%d",&N);

	for(i = 0; i < N; i++){
		scanf("%d %d",&l,&r);
		sum += r - l + 1;
	}

	 printf("%d\n",sum);
		
	return 0;
}