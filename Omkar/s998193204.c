
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main() {

	int n;
	int a[1001];
	int even_a[1001];
	int count = 0;
	int false_count = 0;

	scanf("%d", &n);

	for(int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}

	for(int i = 0; i < n; i++) {
		if(a[i] % 2 == 0) {
			even_a[i] = a[i];
			count++;
		}
	}

	for(int i= 0; i < count; i++) {
		if((even_a[i] % 3 != 0) && (even_a[i] % 5 != 0)) {
			false_count++;
			break;
		}
	}

	if(false_count == 0) {
		printf("APPROVED\n");
	}
	else {
		printf("DENIED\n");
	}

	return 0;

}
