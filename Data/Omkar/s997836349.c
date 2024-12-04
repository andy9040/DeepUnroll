#include <stdio.h>
#include <stdlib.h>

int main(){
	int A, B, i;
	scanf("%d%d", &A, &B);
	char *S = (char *)malloc(sizeof(char) * (A + B + 2));
	scanf("%s", S);
	for(i = 0; i <= A + B; i++){
		if(i == A){
			if(S[i] != '-'){
				printf("No\n");
				return 0;
			}
		}
		else{
			if(!((int)'0' <= (int)S[i] && (int)S[i] <= (int)'9')){
				printf("No\n");
				return 0;
			}
		}
	}
	printf("Yes\n");
	return 0;
}