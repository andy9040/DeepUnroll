#include<stdio.h>
int cnt;
void marge(int a[], int n, int left, int mid,int right) {
	int n1, n2,i,j,k,l[10000],r[10000];
	n1 = mid - left;
	n2 = right - mid;
	for (i = 0; i < n1; i++) {
		l[i] = a[left + 1];
	}
	for (i = 0; i < n2; i++) {
		r[i] = a[mid + 1];
	}
	i = j = 0;
	l[n1] = r[n2] = 200000000;
	for (k = left; k < right; k++) {
		cnt++;
		if (l[i] <= r[j]) {
			a[k] = l[i++];
		}
		else {
			a[k] = r[j++];
		}
	}
}

void margesort(int a[], int n, int left, int right) {
	int mid;
	if (left + 1 < right) {
		mid = (left + right) / 2;
		margesort(a, n, left, mid);
		margesort(a, n, mid,right);
		marge(a, n, left, mid, right);
	}
}

int main(void) {
	int i, n, a[10000];
		cnt = 0;
	for (i = 0; i < n; i++) {
		scanf("%d ", &a[i]);
	}
	margesort(a, n, 0, n);
	for (i = 0; i < n; i++) {
		printf("%d ",a[i]);
	}
	printf("\n%d\n",cnt);
	return 0;
}

