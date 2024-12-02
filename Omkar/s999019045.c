#include <stdio.h>
int main(void){
	int t[10];
	int tb;
	int i;
	
	for(i = 0;i < 10;i++)
		t[i] = 0;
	
	while(scanf("%d",&tb) != EOF){
		printf("%d\n",tb);
		if(tb > 0){
			for(i = 0;i < 10;i++){
				if(t[i] == 0){
					t[i] = tb;
					break;
				}
			}
		}else{
			for(i = 9;i >= 0;i--){
				if(t[i] != 0){
					printf("%d\n",t[i]);
					t[i] = 0;
					break;
				}
			}
		}
	}
		
	return 0;
}