#include<stdio.h>
#include<string.h>
 
int main(){
	int a;
  	char s[5];
  	scanf("%s", s);
	if(strcmp(s,"SUN")==0){  
  	a=7;
    } else if(strcmp(s,"MON")==0){
    a=6;  
    } else if(strcmp(s,"TUE")==0){
    a=5;  
    } else if(strcmp(s,"WED")==0){
    a=4;  
    } else if(strcmp(s,"THU")==0){
    a=3;  
    } else if(strcmp(s,"FRI")==0){
    a=2;  
    } else if(strcmp(s,"SAT")==0){
    a=1;
    }
      
  	printf("%d",a);
  
  return 0;
}
