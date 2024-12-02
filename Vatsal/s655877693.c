#include<stdio.h>

void swap(int *nx, int *ny) {
	int temp = *nx;
	*nx = *ny;
	*ny = temp;
}

void sort3(int *n1, int *n2, int *n3) {
	if (*n1 > *n2) swap(n1, n2);
	if (*n2 > *n3) swap(n2, n3);
	if (*n1 > *n2) swap(n1, n2);
}

int main(void) {
	int A, B, C;

	//int count_A = 0, count_B = 0;


		scanf("%d %d %d", &A, &B, &C);
		//int count_A = 0, count_B = 0;
		
		sort3(&A, &B, &C);



		if (A==5 && B==5 && C==7) {
			printf("YES");
		}
		else {
			printf("NO");
		}
		/*
		if (A == 5 || A == 7)
		{
			if (A == 5) count_A++;
			else  count_B++;

			if (B == 5 || B == 7)
			{
				if (B == 5) count_A++;
				else  count_B++;

				if (C == 5 || C == 7)
				{
					if (C == 5) count_A++;
					else  count_B++;

					if (count_A == 2 && count_B == 1)  printf("Yes");
					else printf("No");
				}
				else printf("No");
			}
			else printf("No");
		}
		else printf("No");
		*/

	return 0;
}