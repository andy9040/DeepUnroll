#include <stdio.h>

int main(){
	int i,n,a,cnt=0;
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		scanf("%d", &a);
		if(i%2==1&&a%2==1){
			cnt++;
		}
	}
	printf("%d\n",cnt);
	return 0;
}