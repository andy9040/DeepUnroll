#include<stdio.h>
#include<stdlib.h>
#include<math.h>




int main()
{
	int W,H,N;
	int x[100];
	int y[100];
	int a[100];
	int i,j,k,sum=0;
	int s[100][100];
	
	scanf ("%d %d %d",&W,&H,&N);
	
	for (i=0;i<=N-1;i++){
		scanf("%d %d %d",&x[i],&y[i],&a[i]);
	}
	for (i=0;i<=99;i++){
		for (j=0;j<=99;j++){
			s[i][j]=0;
		}
	}
	
	for (i=0;i<W;i++){
		for (j=0;j<H;j++){
			s[i][j]=1;
		}
	}
	
	
	for (k=0;k<N;k++){
		switch(a[k]){
		case 1:
			for(i=0;i<x[k]-1;i++){
				for (j=0;j<H;j++){
					s[i][j]=0;
				}
			}
			break;
		
		case 2:
			for(i=W;i>x[k]-1;i--){
				for (j=0;j<H;j++){
					s[i][j]=0;
				}
			}
			break;
		case 3:
			for(j=0;j<y[k]-1;j++){
				for (i=0;i<W;i++){
					s[i][j]=0;
				}
			}
			break;
		case 4:
			for(j=H;j>y[k]-1;j--){
				for (i=0;i<W;i++){
					s[i][j]=0;
				}
			}
			break;
		default:
			break;
		}
		
	}
			
	for (i=0;i<=99;i++){
		for (j=0;j<=99;j++){
			sum=sum+s[i][j];
		}
	}
	
		printf("%d",sum);
	
	
	return 0;
}