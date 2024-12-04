#include<stdio.h>

int m[]={0,31,29,31,30,31,30,31,31,30,31,30,31},s,a,b,i;

int main(){
	scanf("%d%d",&a,&b);
	while(a!=0 && b!=0){
		s=0;
		for(i=1;i<a;i++)s+=m[i];
		s+=b;
		if(s%7==0)printf("Wednesday\n");
		if(s%7==1)printf("Thursday\n");
		if(s%7==2)printf("Friday\n");
		if(s%7==3)printf("Saturday\n");
		if(s%7==4)printf("Sunday\n");
		if(s%7==5)printf("Monday\n");
		if(s%7==6)printf("Tuesday\n");
		scanf("%d%d",&a,&b);
	}
	
	return 0;
}