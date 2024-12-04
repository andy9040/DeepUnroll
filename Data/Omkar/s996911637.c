#include<stdio.h>

void main()
{
	int num,i;
	char *hoge;
	scanf("%s",hoge);
	
	num = 0;
	
	for(i = 0; i <10; i++){
		if(hoge[i] == 'A' || hoge[i] == 'C' || hoge[i] == 'G' || hoge[i] == 'T'){
			num++;
		}
	}
	
	printf("%d\n",num);
	
	exit(0);
}