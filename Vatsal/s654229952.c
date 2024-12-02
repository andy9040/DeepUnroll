// AtCoder ABC064 D - Insertion
// 2020.1.25 bal4u

#include <stdio.h>

#define gc() getchar_unlocked()
#define pc(c) putchar_unlocked(c)

int in() {  // 整数の入力
	int n = 0; int c = gc();
	if (c == '-') {	c = gc();
		do n = 10*n + (c & 0xf), c = gc(); while (c >= '0');
		return -n;
	}
	do n = 10*n + (c & 0xf), c = gc(); while (c >= '0');
	return n;
}

void ins(char *s) { // 文字列の入力　スペース以下の文字で入力終了
	do *s = gc();
	while (*s++ > ' ');
	*(s-1) = 0;
}

void outs(char *s) { while (*s) pc(*s++); }

int N;
char buf[220];
char *top = buf+110;

int main()
{
	int k;
	char *p;
	N = in();
	ins(p = top);
	k = 0;
	while (*p) {
		if (*p == '(') k++;
		else {
			if (k > 0) k--;
			else *--top = '(';
		}
		p++;
	}
	while (k-- > 0) *p++= ')';
	
	outs(top);
	pc('\n');
	return 0;
}
