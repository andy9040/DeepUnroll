#include <stdio.h>
#include <string.h>

int main(void) {
	int i, j;
	int number, lmnumber, lmword, swap, count;
	char str[500][33];
	int sstr[500];
	
	i = j = lmnumber = number = 0;
	while (str[j][i] = getchar()) {
		lmnumber = i > lmnumber ? i : lmnumber;
		if( str[j][i] == ' ') {
			str[j][i] = '\0';
			j++;
			i = -1;
		}
		else if( str[j][i] == '\n') {
			str[j][i] = '\0';
			break;
		}
		i++;
	}
	number = j + 1;
	for (i = 0; i < number; i++)
		sstr[i] = i;
	for (i = number; i > 1; i--)
		for (j = 0; j < i - 1; j++)
			if( strcmp(str[sstr[j]], str[sstr[j+1]]) == 1) {
				swap = sstr[j];
				sstr[j] = sstr[j+1];
				sstr[j+1] = swap;
			}
	for (i = j = count = 0; i < number; i++) {
		if( strlen(str[i]) == lmnumber)
			lmword = i;
		if( strcmp(str[sstr[i]], str[sstr[i+1]]) == 0) {
			if( j == 0)
				j = 2;
			else
				j++;
			count = j > count ? sstr[i] : count;
		}
		else
			j = 0;
	}
	printf("%s %s\n", str[count], str[lmword]);
	return 0;
}