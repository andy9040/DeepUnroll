#include<stdio.h>

int main()
{
	int input;
	int stack[10];
	int sp=0;
	int outtrain[11];
	int i;

	for(i=0;i<10;i++){stack[i]=0;}
	for(i=0;i<11;i++){outtrain[i]=0;}
	i=0;
	while(scanf("%d",&input)!=EOF)
	{
		if(input==0)
		{	

			outtrain[i]=stack[sp];
			stack[sp]=0;
			i++;
			if(sp!=0){sp--;}
		}
		else
		{
			if(stack[0]!=0){sp++;}
			stack[sp]=input;
		}
	printf("%d",sp);
	}
	i=0;
	while(outtrain[i]!=0)
	{
		printf("%d\n",outtrain[i]);
		i++;
	}
	return 0;
}