#include<stdio.h>

int main(){
	int x,n;
	scanf("%d %d",&x,&n);
	int i,p[n + 1],tmp,min,max;
	for(i = 0; i < n; i++){
		scanf("%d",&tmp);
		p[tmp] = 1;
	}
	min = x;
	max = x;
	for(i = 0; i < n / 2 + 1; i++){
		if(p[min] == 0 || p[max] == 0){
			if(p[min] == 0){
				printf("%d",min);
				break;
			} else {
				printf("%d",max);
				break;
			}
		}
		min--;
		max++;
		if(min < 0){
			printf("%d",min);
			break;
		}
	}
	if(n == 0){
		printf("%d",x);
	}

	return 0;
}
