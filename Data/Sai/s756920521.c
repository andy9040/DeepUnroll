#include <stdio.h>

int main(void)
{
	int a;
	int i = 0;
	
	while (1){
		i++;
		scanf("%d", &a);
		if(a == 0){
			break;
		}
		printf("Case %d : %d\n", i, a);
	}
	return(0);
}