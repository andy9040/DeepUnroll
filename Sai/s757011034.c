#include <bits/stdc++.h>

int ri() {
	int n;
	scanf("%d", &n);
	return n;
}

int main() {
	int a = ri();
	int b = ri();
	puts(b * 2 >= a ? "unsafe" : "safe");
	return 0;
}
