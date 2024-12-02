#include<stdio.h>
#include<ctype.h>

int main(){

	int i;
	char s[500];

	while(scanf("%100[^\n]%*[^\n]",s)!=EOF){
		getchar();
		i=0;
		while(s[i]!='\0'){
			if(islower(s[i])) s[i]=s[i]-32;
			i++;

		}
		 printf("%s",s);


	}


	return 0;

}