#include<stdio.h>
int main()
{
	int n,m,a[100];
	int i,c=0;
	scanf("%d %d",&n,&m);
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	for(i=0;i<n;i++){
		if(4*m>=a[i]){
			c++;
		}
	}
	if(c>=m){
		printf("Yes\n");
	}
	else{
		printf("No\n");
	}
	return 0;
}