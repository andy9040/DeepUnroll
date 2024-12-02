#include<stdio.h>
#include<stdlib.h>

int main(){
	int n, k;
	scanf("%i %i", &n, &k);
	int a[n], b[n];
	for(int i = 0; i < n; i++){
		scanf("%i", &b[i]);
	}

	int i = 0;
	while(i < k){
		for(int m = 0; m < n; m++){
			a[m] = b[m];
		}
		for(int j = 0; j < n; j++){
			b[j] = 0;
			for(int l = 0; l < n; l++){
				int dif = abs(j - l);
				if(dif <= a[l]){
					b[j] += 1;
				}
			}
		}
		i++;
	}

	for(int i = 0; i < n; i++){
		printf("%i ", b[i]);
	}
	printf("\n");

	return 0;
} 
