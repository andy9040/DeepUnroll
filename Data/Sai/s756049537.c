#include<stdio.h>
int main()
{
	int x,n,p[101],f=0,t=101,a=0,i,j;

	scanf("%d%d",&x,&n);
	for(i=0;i<n;i++)
		scanf("%d",&p[i]);

	for(i=0;i<=101;i++){
		for(j=0;j<n;j++)
			if(i==p[j])
				f=1;
		if(f==0&&abs(x-i)<t){
			t=abs(x-i);
			a=i;
		}
		f=0;
	}
	printf("%d",a);
	return 0;
}