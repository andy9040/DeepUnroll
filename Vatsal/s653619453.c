#include<stdio.h>
int main()
{
	int a,b,arr[15]={0,14,13,12,11,10,9,8,7,6,5,4,3,2};
	scanf("%d %d", &a, &b);
	if(arr[a]>arr[b]){
		printf("Alice\n");
	}
	else if(arr[a]<arr[b]){
		printf("Bob\n");
	}
	else{
		printf("Draw\n");
	}
	return 0;
}