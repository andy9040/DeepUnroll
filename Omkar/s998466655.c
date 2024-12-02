#include<stdio.h>
int main(){
	int x,y,z,n;
	scanf("%d%d%d",&x,&y,&z); 
	
	if ( y+2*z<=x ){
		n=(x-z)/(z+y);
		printf("%d",n);
		
	}
	
	return 0;
}