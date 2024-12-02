#include<stdio.h>
#include<string.h>
int main() {

	int k, i;
	char s[101];

	scanf("%d", &k);
	scanf("%s", s);

	if (strlen(s) <= k)
		printf("%s", s);

	else {
		for (i = 0; i < k; i++)
			printf("%c", s[i]);
		printf("...");
	}

	return 0;
}