#include <stdio.h>
#include <string.h>

int main() {
	
	int a, b, strip;
	
	scanf("%d %d", &a, &b);
	
	
	char s[100];
	
	scanf("%s", &s);
	
	for(int i=0; i<=strlen(s); i++){
		if(s[i]=='-'){
			strip++;
		}
	}
	
	if(s[a]!='-'){
		printf("No");
		return 0;
	}
	
	
	else if(strip>>1){
		printf("No");
		return 0;
	}
	
	else if(strlen(s)!=a+b+1){
		printf("No");
		return 0;
	}
	
	else {
		printf("Yes");
		return 0;
	}
	
	
}