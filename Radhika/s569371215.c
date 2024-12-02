#include <stdio.h>

int main(void)
{
	int a, b, c, d, e, q;
	int fu, ze;
	int card[5];
	int check[5];
	int straight[5] = {1, 10, 11, 12, 13};
	
	while (scanf("%d,%d,%d,%d,%d", &card[0], &card[1], &card[2], &card[3], &card[4]) != EOF) {
		for (a = 0; a < 5; a++) {
			fu = a;
			for (b = a + 1; b < 5; b++) {
				if (card[b] < card[fu]) {
					fu = b;
				}
			}
			ze = card[a];
			card[a] = card[fu];
			card[fu] = ze;
		}
		for (a = 0; a < 5; a++) {
			check[a] = 0;
		}
		d = 0;
		q = 0;
		if (card[0] == straight[0]) {
			q++;
		}
		for (a = 1; a < 5; a++) {
			if (card[a - 1] == (card[a] - 1)) {
				d++;
			}
			if (card[a] == straight[a]) {
				q++;
			}
		}
		for (a = 0; a < 5; a++) {
			c = 0;
			for (b = a + 1; b < 5; b++) {
				if (card[a] == card[b] && card[a] != -1 && card[b] != -1) {
					c++;			
					card[b] = -1;
				}
			}
			if (c == 1) {
				check[0]++;
			}
			else if (c == 2) {
				check[1]++;
			}
			else if (c == 3) {
				check[2]++;
			}
			card[a] = -1;
		}
		if (check[0] == 2) {
			printf("two pair\n");
		}
		
		else if (check[0] == 1) {
			if (check[1] == 1) {
				printf("full house\n");
			}
			else {
				printf("one pair\n");
			}
		}		
		else if (check[1] == 1) {
			printf("three card\n");
		}
		else if (check[2] == 1) {
			printf("four card\n");
		}
		else if (d == 4 || q == 5) {
			printf("straight\n");
		}
		else {
			printf("null\n");
		}
	}
	
	return (0);
}