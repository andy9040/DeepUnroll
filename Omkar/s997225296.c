#include <stdio.h>

int abs(int x, int y)
{
	if(x >= y){
		return(x - y);
	}
	else{
		return(y - x);
	}
}

int main(void)
{
	int hh[100];
	int mm[100];
	int MM[100];
	int ds;
	int i;
	float j[2];
	float k[2];
	float l[2];
	
	scanf("%d", &ds) ;
	
	while(ds != 0){
		j[0] = 0;
		j[1] = 1;
		k[0] = 0;
		k[1] = 1;
		l[0] = 0;
		l[1] = 1;
		for (i = 0; i < ds; i++){
			scanf("%d%*c%d%d",&hh[i], &mm[i], &MM[i]);
			if(00<= mm[i] && mm[i] <= 59 && 00 <= MM[i] && MM[i] <= 59){
			if (11 <= hh[i] && hh[i] <= 14){
				j[0]++;
				if(mm[i] > MM[i]){
					MM[i] += 60;
				}
				if (abs(mm[i],MM[i]) > 8){
					j[1]++;
				}
			}
		
			else if (18 <= hh[i] && hh[i] <= 20){
				k[0]++;
				if(mm[i] > MM[i]){
					MM[i] += 60;
				}
				if (abs(mm[i],MM[i]) > 8){
					k[1]++;
				}
			}
			
			else if ((21 <= hh[i] && hh[i] <= 23)||(00 == hh[i] || hh[i] == 01)){
				l[0]++;
				if(mm[i] > MM[i]){
					MM[i] += 60;
				}
				if (abs(mm[i],MM[i]) > 8){
					l[1]++;
				}
			}
		}
		}
		
		printf("lunch ");
		if(j[0] == 0){
			printf("no guest\n");
		}
		else{
			printf("%.0f\n", 100 /j[1]);
		}
		
		printf("dinner ");
		if(k[0] == 0){
			printf("no guest\n");
		}
		else{
			printf("%.0f\n", 100 /k[1]);
		}
		
		printf("midnight ");
		if(l[0] == 0){
			printf("no guest\n");
		}
		else{
			printf("%.0f\n", 100 /l[1]);
		}
		
		scanf("%d", &ds);
	}
	return (0);
}