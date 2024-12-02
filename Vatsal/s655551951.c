#include<stdio.h>
int main(void)
{
	int n,d,x[11][11],i,j,a[11]={0},p=0;
	scanf("%d%d",&n,&d);
	for(i=0;i<n;i++){
		for(j=0;j<d;j++){
			scanf("%d",&x[i][j]);
		}
	}
	for(i=0;i<n;i++){
		for(j=0;j<d;j++){
			if(i==n-1){
				a[i]+=(x[i][j]-x[0][j])*(x[i][j]-x[0][j]);
			}
			else{
				a[i]+=(x[i][j]-x[i+1][j])*(x[i][j]-x[i+1][j]);
			}
		}
	}
	for(i=0;i<n;i++){
		for(j=1;j<=100;j++){
			if(a[i]==j*j){
				p++;
			}
		}
	}
	printf("%d\n",p);
	return 0;
}