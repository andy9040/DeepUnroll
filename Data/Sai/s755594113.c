#include<stdio.h>
#include<string.h>

int main(){
	int N,i,j;
	scanf("%d",&N);
	char W[101][11];
	for(i=0;i<N;i++)scanf("%s",W[i]);
	
	for(i=0;i<N;i++){
		for(j=i+1;j<N;j++){
			if(strcmp(W[i],W[j])==0){
				printf("No\n");
				return 0;
			}
		}
	}
	
	char last=W[0][strlen(W[0])-1];
	
	for(i=1;i<N;i++){
		if(last!=W[i][0]){
			printf("No\n");
			return 0;
		}
		if(i<N-1)last=W[i][strlen(W[i])-1];
	}
	printf("Yes\n");
	return 0;
}