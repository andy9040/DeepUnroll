#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*student ID:107033215 Name:TSENG YU WEI Department:PME22*/

int main()
{
	char input[1000][33], maximumNumber[33], eachWord[33], count[1000];
	int each, max=0, i=0, j, countnum=0, k;
	while(scanf("%s", &input[i]) != EOF) 
	{	
		j=0;
		while (j<i)
		{
			count[i]=1;
			if (strcmp(input[j], input[i])==0)
			{
				count[j]++;
			}
			j++;
		}
		each=strlen(input[i]);
		strcpy(eachWord, input[i]);
		if (each>max)
		{
			max=each;
			strcpy(maximumNumber, eachWord);
		}
		i++;
	}
	for (k=0;k<i;k++)
	{
		if (count[k]>countnum)
		{
			countnum=k;
		}
	}
	printf("%s %s\n", input[countnum], maximumNumber);
	return 0;
}


