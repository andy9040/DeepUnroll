#include<stdio.h>

int main()
{
	char c;
	int sum1 = 0, sum2 =0;

	while(1) {
		c = getchar();
		if (c == '0') {
			sum1++;
		}
		else if (c == '1') {
			sum2++;
		}
		else {
			break;
		}

		c = getchar();
		if (c == '0') {
			sum2++;
		}
		else if (c == '1') {
			sum1++;
		}
		else {
			break;
		}
	}

	printf("%d", sum1 < sum2 ? sum1 : sum2);
}