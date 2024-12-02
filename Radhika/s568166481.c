#include <stdio.h>
int main(void)
{
	int t[4];
	int n[4];
	int i;
	
	for(i=0;i<4;i++)
	scanf("%d %d",&t[i],&n[i]);
	
	for(i=0;i<4;i++){
		switch(t[i]){
			case 1:t[i]=6000; break;
			case 2:t[i]=4000; break;
			case 3:t[i]=3000; break;
			case 4:t[i]=2000; break;
		}
	}
	
	for(i=0;i<4;i++)
	printf("%d\n",t[i]*n[i]);
	
	return 0;
}