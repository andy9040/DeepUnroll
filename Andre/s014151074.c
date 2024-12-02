#include <stdio.h>
#include <string.h>

int main(void)
{
	char word[100];
	char text[100];
	int count;

	scanf("%s", word);

	while(1){
		scanf("%s", text);
		if(strcmp(text, word) == 0){
			count++;
		}

		if(strcmp(text, "END_OF_TEXT") == 0) break;

	}

	printf("%d\n", count);

	return 0;
}