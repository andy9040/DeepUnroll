#include<stdio.h>
#include<string.h>
int main(){
	int i,j,a[9],f[20],y;
	while(scanf("%d,%d,%d,%d,%d",&a[0],&a[1],&a[2],&a[3],&a[4])!=EOF){
		memset(f,0,sizeof(f));
		for(i=0;i<5;i++)f[a[i]]++;
		y=1;
		for(i=1;i<14;i++){
			if(f[i]==4)y=7;
			else if(f[i]==3 && y<4){
				y=4;
				for(j=1;j<14;j++)if(f[j]==2)y=6;
			}
			else if(f[i]==2 && y<2){
				y=2;
				for(j=1;j<14;j++)if(i!=j && f[j]==2)y=3;
			}
		}
		for(i=1;i<11;i++){
			if(f[i]==1 && f[i+1]==1 && f[i+2]==1 && f[i+3]==1 && f[(i+4)%13]==1 && y<5)y=5;
		}
		
		if(y==1)printf("null\n");
		else if(y==2)printf("one pair\n");
		else if(y==3)printf("two pair\n");
		else if(y==4)printf("three card\n");
		else if(y==5)printf("straight\n");
		else if(y==6)printf("full house\n");
		else if(y==7)printf("four card\n");
	}
	return 0;
}