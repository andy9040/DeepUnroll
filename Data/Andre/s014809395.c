#include <stdio.h>

int main(void){
	int m,d,s;
	
	scanf("%d %d",&m,&d);
	
	while((m==0)&&(d==0)){
	if(m==1){
		s=0;
	}
	if(m==2){
		s=31;
	}
	if(m==3){
		s=60;
	}
	if(m==4){
		s=91;
	}
	if(m==5){
		s=121;
	}
	if(m==6){
		s=152;
	}
	if(m==7){
		s=182;
	}
	if(m==8){
		s=213;
	}
	if(m==9){
		s=244;
	}
	if(m==10){
		s=274;
	}
	if(m==11){
		s=305;
	}
	if(m==12){
		s=335;
	}
	
	s+=d;
	
	s=s%7;
	
	if(s==0){
		printf("Wednesday");
	}
	if(s==1){
		printf("Thursday");
	}
	if(s==2){
		printf("Friday");
	}
	if(s==3){
		printf("Saturday");
	}
	if(s==4){
		printf("Sunday");
	}
	if(s==5){
		printf("Monday");
	}
	if(s==6){
		printf("Tuesday");
	}
	
	
	}
	return 0;
}