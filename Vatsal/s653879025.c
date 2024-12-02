#include<stdio.h>
int main()
{
	int x,y,z,i,a;
	scanf("%d%d%d",&x,&y,&z);
	i=1;
	x=x-z*2;
	a=x;
	while(a>0){
		a=x-i*y-(i-1)*z;
		if(a<0){
			break;
		}
		i+=1; 
  	}
	printf("%d",i-1);
}