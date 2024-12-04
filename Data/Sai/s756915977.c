#include <stdio.h>
#define N 4
int main(void) {

	int x[N];
    int i;

		for(i = 0; i != 4; i++){
			scanf("%d", &x[i]);
		    printf("case %d: %d\n",i,x[i]);
			if(x[i] == 0){
				break;
				}
		}		
	return 0;
}