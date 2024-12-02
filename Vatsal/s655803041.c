//#define DEBUG
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#define MAX_T 202
#define MAX_N 100

int main() {
#ifdef DEBUG

#endif
	char s[4];
	scanf("%c%c%c", &s[0], &s[1], &s[2]);

	int cnt = 0;
	int i;
	for (i = 0; i < 3; i++) {
		if (s[i] == '1')cnt++;
	}

	printf("%d\n", cnt);
}