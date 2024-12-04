#include <stdio.h>

int main(void)
{
	int kosuu;
	int saidai;
	int saisyou;
	int ie[1001];
	int a;  /*くりかえし*/
	
	
	scanf("%d",&kosuu);
	
	for(a = 0;a < kosuu;++a){
		scanf("%d",&ie[a]);
	}
	
	saidai = 0;
	saisyou = 1000;
	
	for(a = 0;a < kosuu;++a){
		if(saidai < ie[a]){
			saidai = ie[a];
		}
		if(saisyou > ie[a]){
			saisyou = ie[a];
		}
	}
	printf("%d\n",saidai - saisyou);
	
	return(0);
}
