#include <stdio.h>
int main()
{
	int i,j,k=0,kazu=0,a=0;
	char ring[101][101],n[101];
	scanf("%s %d",n,&i);
	
	for(j=0;j<i;j++){
		scanf("%s",ring[j]);
	}
	for(j=0;j<i;j++){
		a=0;
		for(k=0;k<10;k++){
			if(n[a]==ring[j][k]){
				a++;
				if(n[a]=='\0'){
					kazu++;
					break;
				}
				else if(ring[j][k+1]=='\0'){
					k=-1;
				}
				
			}
		}
	}
	printf("%d\n",kazu);
		return 0;
}

