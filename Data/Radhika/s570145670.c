#include <stdio.h>

int sum[7];
int main(void)
{
	int i, j, n;
	int m, e, j;
	float ave;
	
	while (scanf("%d", &n), n != 0){
		for (j = 0; j < n; j++){
			scanf("%d %d %d", &m, &e, &j);
			ave = (m + e + j) / 3.0;
			
			if (m == 100 || e == 100 || j == 100){
				printf("A\n");
			}
			else if ((m + e) / 2.0 >= 90){
				printf("A\n");
			else if (ave >= 80){
				printf("A\n");
			}
			else if (ave >= 70){
				printf("B\n");
			}
			else if (ave >= 50 && (m >= 80||e = 80)){
				printf("B\n");
			}
			else {
				printf("C\n");
			}
		}
	}
	
	return 0;
}