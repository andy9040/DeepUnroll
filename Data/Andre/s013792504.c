// ?????? ??????
#include<stdio.h>
int main(void)
{
	int t,n,i,g;
	for (i=0;i<4;i++){
		scanf("%d%d",&t,&n);
		if (t==1){
			g=6000*n;
			printf("%d",g);
		}
		else if (t==2){
			g=4000*n;
			printf("%d",g);
		}
		else if (t==3){
			g=3000*n;
			printf("%d",g);
		}
		else if (t==4){
			g=2000*n;
			printf("%d",g);
		}
	}
	return 0;
}