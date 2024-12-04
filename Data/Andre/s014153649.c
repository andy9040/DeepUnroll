#include<stdio.h>
#include<math.h>


int main()
{
	double north=0,east=0,rad;
	int angle=0;
	int distance,tmpang;
	
	do
	{
		scanf("%d,%d",&distance,&tmpang);
		rad=angle*3.141592654/180;
		north+=cos(rad)*distance;
		east+=sin(rad)*distance;
		angle+=tmpang;
	}while(distance!=0||tmpang!=0);
	printf("%d\n%d\n",(int)east,(int)north);
	return 0;
}