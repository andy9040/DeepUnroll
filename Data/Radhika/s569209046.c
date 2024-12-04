#include <stdio.h>

int main(void)
{
	int n, m, in, ot, s, max;
	int i, j;

	scanf("%d%d", &n, &m);
	s = m; max = m;
	for (i = 0; i < n; i++) {
		scanf("%d%d", &in, &ot);
		s += in - ot;
		if (s < 0) {
			max = 0; break;
		}
		else if (s > max)
			max = s;
	}
	printf("%d\n", max);

	return 0;
}