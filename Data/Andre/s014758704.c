#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 11

int main(){

	int len;
	char migi[N] = "yuiophjklnm";
	char input[128];
	int cnt;
	int flag,a_flag;
	int flag2;
	int i,j;

	while(1){

		cnt = 0;
		flag2 = 0;

		scanf("%s",input);
		len = strlen(input);


		if(input[0] == '#' ){
			break;
		}
		for(i=0; i<len; i++){
			for(j=0; j<N; j++){
				if(input[i] == migi[j]){
					flag = 1;
					break;
				}
				else{
					flag = 0;
				}
			}
			if(flag2 == 0){
				flag2 = 1;
				a_flag = flag;
			}

			if(flag != a_flag){
				cnt++;
			}
			a_flag = flag;

		}
		printf("%d\n",cnt);
	}

	return 0;
}