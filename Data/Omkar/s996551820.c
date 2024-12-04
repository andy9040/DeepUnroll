#include <stdio.h>
int main()
{
	int i[10],o[10],n,c[2]={0};
	do{
		scanf("%d",&n);
		if(n)
			i[c[0]]=n,c[0]++;
		else
			c[0]--,o[c[1]]=i[c[0]],c[1]++;
	}while(c[0]);
	for(n=0;n<c[1];n++)
		printf("%d\n",o[n]);
	return 0;
}