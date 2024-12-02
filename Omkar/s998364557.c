#include<stdio.h>
int main(){
	int m,d,i=0,j,k;
	int W;
	int s=0;
	int key[1000];
	
	while(1){
		scanf("%d %d",&m,&d);
		if(m==0)break;
		
		for(k=1;k<m;k++){
			if(i==1 || i==3 || i==5 || i==7 || i==8 || i==10 || i==12)s+=31;
			else if(i==4 || i==6 || i==9 || i==11 )s+=30;
			else if(i==2)s+=29;
		}
		
		W=s+d;
		if(W%7==0)key[i]=0;
		else if(W%7==1)key[i]=1;
		else if(W%7==2)key[i]=2;
		else if(W%7==3)key[i]=3;
		else if(W%7==4)key[i]=4;
		else if(W%7==5)key[i]=5;
		else if(W%7==6)key[i]=6;
		
		++i;
	}
	for(j=0;j<i;j++){
		if(key[j]==4)printf("Sunday\n");
		if(key[j]==5)printf("Monday\n");
		if(key[j]==6)printf("Tuesday\n");
		if(key[j]==0)printf("Wednesay\n");
		if(key[j]==1)printf("Thursday\n");
		if(key[j]==2)printf("Friday\n");
		if(key[j]==3)printf("Saturday\n");
	}
return 0;
}