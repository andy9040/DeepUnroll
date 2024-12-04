#include<stdio.h>
int main()
{
	int a,b,i,n;
	while(1){
	scanf("%d %d",&a,&b);
	if(a==0&&b==0)
		break;
	for(i=1;i<=a;i++){
		for(n=1;n<=b;n++){
			if(i==1||i==a)
			   printf("#");
			else if(n==1||n==b)
			   printf("#");
			else 
				printf(".");
			}
	printf("\n");
	}
	}
	return 0;
}