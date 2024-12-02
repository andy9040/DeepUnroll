#include<stdio.h>
#include<math.h>
#define PAI 3.141592

int main()
{
	double hos,x=0.0,y=0.0;
	double rad;
	char c;

	while(1)
	{
		scanf("%lf%c%lf",&hos,&c,&rad);
		if(hos==0.0 && rad==0.0)
			break;
		rad=90.0-rad;
		x+=hos*cos(rad*PAI/180.0);
		y+=hos*sin(rad*PAI/180.0);
				
	}

	printf("%d\n%d\n",(int)x,(int)y);
	return 0;
}