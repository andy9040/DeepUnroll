#include <stdio.h>
#include <string.h>

int n;
int main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		int t;
		scanf("%d",&t);
		if(t%2==0&&(t%3!=0&&t%5!=0)){
			puts("DENIED");
			return 0;
		}
	}
	puts("APPROVED");
}