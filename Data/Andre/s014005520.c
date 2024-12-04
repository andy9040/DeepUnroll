#include <stdio.h>
#include <string.h>


int main(void)
{
	
	int n;
	long int ans = 1;
	long int max = 1000000000;
	long int min = 1000000000;
	long int kou_max;
	long int a[100000];
	long int i, j, k;
	int flg;
	int count = 0;
	
	scanf("%d", &n);
	
	for(i = 0; i < n; i++) {
		scanf("%ld", &a[i]);
		if(min > a[i]) {
			min = a[i];
		} else if(max > a[i]) {
			max = a[i];
		}
	}
	
	for(j = max; j >= 2; j--) {
		count = 0;
		for(k = 0; k < n; k++) {
			if(a[k] % j == 0) {
				count++;
			}
			if(count >= n - 1) {
				printf("%ld\n", j);
				return 0;
			}
		}
	}
	
	return 0;
}