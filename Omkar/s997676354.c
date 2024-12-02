#include<stdio.h>

int main(){
	double a,b,c,d,e,f;
	double ans,ans2;

	while(scanf("%lf%lf%lf%lf%lf%lf",&a,&b,&c,&d,&e,&f)!=EOF){

		    ans=(e*c-b*f)/(a*e-b*d);
			ans2=(c*d-a*f)/(b*d-a*e);
	
					if((e*c-b*f)==0){ ans=0.000 ; }
			else if((c*d-a*f)==0){ ans2=0.000 ;}

		printf("%.3f %.3f\n",ans,ans2);
	}
	return 0;
}