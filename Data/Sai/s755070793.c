#include<stdio.h>

int main(){
	int cards[201] = { 0 };
	int Temp[201] = { 0 };
	int temp;
	int i,j;
	int n,m,k,l;
	
	scanf("%d",&n);
	for(i=1;i<=n*2;i++){
		cards[i]=i;
	}
	scanf("%d",&m);
	for(i=1;i<=m;i++){
		scanf("%d",&k);
		if(k==0){												//OÌ
			for(j=1;j<201;j++){
				Temp[j]=cards[j];
			}
			for(j=1,temp=1;j<=n*2;j+=2,temp++){
				cards[j]=Temp[temp];
			}	
			for(j=2;j<=n*2;j+=2,temp++){
				cards[j]=Temp[temp];
			}
		}														//±±ÜÅ
		else{													//else
			for(i=1;i<=k;k++){
				Temp[i]=cards[i];
			}
			for(i=1;k<=n*2;k++,i++){
				cards[i]=cards[k];
			}
			for(l=1;i<=n*2;i++,l++){
				cards[i]=Temp[l];
			}
		}														//±±ÜÅB
	}
	for(i=1;;i++){
		if(cards[i]==0){break;}
		printf("%d\n",cards[i]);
	}
	
	
	return 0;
}