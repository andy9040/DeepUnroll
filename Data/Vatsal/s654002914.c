#include<stdio.h>
int main()
{
	int train[100],n,i=0;
	while(1){
		scanf("%d",&n);
		if(n==0){
			printf("%d\n",train[i-1]);
			i--;
			}
		else{
			train[i]=n;
			i++;
			}
	}
	return 0;
}