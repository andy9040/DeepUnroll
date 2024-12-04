#include<stdio.h>
int main(void){
	int a,c,k;
	char b;
	while(1){
	scanf("%d %c %d", &a, &b, &c);
		if(b=='?') break;
		if(b=='+') k=a+c;
		if(b=='-') k=a-c;
		if(b=='*') k=a*c;
		if(b=='/') k=a/c;

	printf("%d\n", k);
};
	return (0);
}