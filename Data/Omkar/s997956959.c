#include<stdio.h>

void main()
{
	int kazu;
	char moji[105];
	int i;

	scanf("%d", &kazu);
	scanf("%s", moji);


	for (i = 0; i < kazu - 1; ++i) {
		printf("%c", moji[i]);
	}
	for (i = 0; moji[i] != '\0'; ++i);
	if (kazu < i) {
		printf("...");
	}

}