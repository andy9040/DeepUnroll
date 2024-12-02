#include <stdio.h>
#define min(a,b) (((a)<(b))?(a):(b))
#define max(a,b) (((a)>(b))?(a):(b))
#define abs(a) (((a)>0)?(a):(-a))

int s[15] = { 1,6,9,36,81,216,729,1296,6561,7776,46656,59049,279936,531441 };
int search(int n) {
	int n1, n2, i;
	if (n > 6) {
		for (i = 0; s[i] < n; i++) {}
		n1 = search(n - s[i]);
		n2 = search(n - s[i - 1]);
		if (n1 > 0 && n2 > 0) {
			return min(n1, n2) + 1;
		}
		else
		{
			return max(n1, n2) + 1;
		}
	}
	else
	{
		return max(n, 0);
	}
}
int main()
{
	int n, ans = 0;
	scanf("%d", &n);
	printf("%d", search(n));
	return 0;
}