#include <stdio.h>
#include <string.h>

int main(void)
{
	char W[12], T[1001];
	char s;
	int i;
	int num;
	
	scanf("%s", W);
	num = 0;
	while (1){
		scanf("%s", T);
		if (strcmp(T, "END_OF_TEXT") == 0){
			 break;
		}
		i = 0;
		while(T[i] != '\0'){
			if (T[i] < 'a' || T[i] > 'z'){
				T[i] -= 32;
			}
			i++;
		}
		if (strcmp(T, W) == 0){
			num++;
		}
	}
	
	printf("%d\n", num);
	
	return (0);
}