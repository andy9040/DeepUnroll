#include<stdio.h>
int main(void)
{
	int t,n,d[4],cnt=1;
	while(cnt!=4){
	scanf("%d %d",&t,&n);
	if(t==1)
	d[cnt]=6000*n;
	else if(t==2)
	d[cnt]=4000*n;
	else if(t==3)
	d[cnt]=3000*n;
	else
	d[cnt]=2000*n;
	cnt++;
	}
	while(cnt!=4)
	printf("%d\n",d[cnt]);

	return 0;
}