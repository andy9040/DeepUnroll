#include <stdio.h>
 
int main(void) {
	int n,a,b,s;
	scanf("%d%d%d",&n,&a,&b);
	if(n*a>b){
		printf("%d",n*a);
	}else{
		printf("%d",b);
	}
 
	// your code goes here
	return 0;
}