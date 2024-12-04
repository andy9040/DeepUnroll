#include <stdio.h>

int main(){
	int n,m,i,j,a[100],b[100];
	for(i=0;i<100;i++) b[i]=0;
	scanf("%d",&n);
	scanf("%d",&m);
	for(i=0;i<m;i++){
		scanf("%d",&a[i]);
	}
	for(i=0;i<m;i++){
		for(j=0;j<n;j++){
			int x;
			scanf("%d",&x);
			if(a[i]==x){
				b[j]++;
			}else{
				b[a[i]]++;
			}
		}
	}
	for(i=0;i<n;i++){
		printf("%d\n",b[i]);
	}
	return 0;
}