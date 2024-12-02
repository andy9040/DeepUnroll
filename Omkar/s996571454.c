#include<stdio.h>
int main(void)
{
	char s[100001];
	int count = 0;
	int i;

	scanf("%s",s);

	if(s[0] == '0'){
		for(i = 0;i < 100001;i++)
			if(i%2 == 0 && s[i] == '1')
				count++;
			if(i%2 == 1 && s[i] == '0')
				count++;
	}

	if(s[0] == '1'){
		for(i = 0;i < 100001;i++)
			if(i%2 == 0 && s[i] == '0')
				count++;
			if(i%2 == 1 && s[i] == '1')
				count++;
	}
		
	printf("%d\n",count);

  return 0;
}