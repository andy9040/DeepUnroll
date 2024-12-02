#include<stdio.h>
#include<stdlib.h>

int cmp( const void *p, const void *q ) {
    return *(int*)p - *(int*)q;
}

int main()
{
	int i, n, m, ans = 0;
    
	scanf("%d %d", &n, &m);
	
	int x[m], diff[m - 1];
	
	for(i = 0; i < m; i++){
		scanf("%d", &x[i]);
	}
	
	qsort(x, m, sizeof(int), cmp);
	
	for(i = 0; i < m - 1; i++){
		diff[i] = abs(x[i + 1] - x[i]);
	}
	
	qsort(diff, m - 1, sizeof(int), cmp);
	
	for(i = 0; i < m - n; i++){
		ans += diff[i];
	}
	
	printf("%d", ans);
	
	return 0;
}