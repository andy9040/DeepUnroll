#include <stdio.h>

int main(void) {
	
	char buf[100];
	int i;
	
	gets(buf);
	
	while(buf[i] != '\0'){
		if(buf[i] >= 97 && buf[i] <=122)
		buf[i] = buf[i] - 32;
		i++;
	}
	
	printf("%s",buf);
	
	return 0;
}