#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


char* Strtolower(char *target) {
	if(target == NULL)
		return NULL;
	int i;
	for(i=0;;i++){
		if(target[i] == '\0')
			break;
		target[i] = tolower(target[i]);
	}

	return target;
}

int main(){
	char targetin[15];
	char *target;
	char text[1000];
	char *word;
	int counter = 0;
	int flag = 1;

	// fgets(target, sizeof(target), stdin);
	scanf("%s\n", targetin);
	target = Strtolower(targetin);
	// fprintf(stderr, "%s\n", target);
	while(NULL != fgets(text, sizeof(text), stdin) && flag){
		// fprintf(stderr, "%s\n", text);
		word = Strtolower(strtok(text, " \n"));
		// fprintf(stderr, "%s\n", word);
		if(strcmp(word, target) == 0)
			counter++;
		if(strcmp(word, "end_of_text") == 0)
			break;
		while(1){
			word = Strtolower(strtok(NULL, " \n"));
			if(word == NULL)
				break;
			// fprintf(stderr, "%s\n", word);
			if(strcmp(word, target) == 0)
				counter++;
			if(strcmp(word, "end_of_text") == 0)
				flag = 0;
		}
		// fprintf(stderr, "here\n");
	}

	printf("%d\n", counter);

	return 0;
}