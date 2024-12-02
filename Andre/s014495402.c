#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int main() {
	int f1, f2, count1 = 0, count2 = 0;
	char i, S[100000];
	bool flag;

	scanf("%s", &S);

	if (S[0] == '0') f1 = -1;
	else f1 = 1;
	for (i = 1; i < strlen(S); i++) {
		if (S[i] == '0') f2 = -1;
		else f2 = 1;
		if (f1 != f2) count1++;
		f1 *= -1;
	}

	if (S[strlen(S) - 1] == '0') f1 = -1;
	else f1 = 1;
	for (i = strlen(S) -1; i >= 0; i--) {
		if (S[i] == '0') f2 = -1;
		else f2 = 1;
		if (f1 != f2) count2++;
		f1 *= -1;
	}

	printf("%d\n", count1 < count2 ? count1 : count2);

	return 0;
}