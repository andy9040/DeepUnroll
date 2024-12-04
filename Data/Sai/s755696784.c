#include <stdio.h>
#include <string.h>

int main(void)
{
	char sstr[16];
	char cstr[16];
	int count = 0;
	
	scanf("%s", sstr);
	while (scanf("%s", cstr), strcmp(cstr, "END_OF_TEXT")){
		if (!strcmp(sstr, cstr)){
			count++;
			continue;
		}
		strcat(cstr, ".");
		if (!strcmp(sstr, cstr)) count++;
	}
	printf("%d\n", count);
	
	return (0);
}