#include<stdio.h>
int main(void)
{
	int n,c,p,i,a,b,d,e;
	a=0;
	scanf("%d %d",&n,&c);
		for(i=0;i<c;i++){
			scanf("%d",&p);
			a=a+p;
		}
	e=n+1;
	b=a/e;
	if(a%e!=0){
		b=b+1;
	}
	printf("%d\n",b);
	return 0;
}
		
