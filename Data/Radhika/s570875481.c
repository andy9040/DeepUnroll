#include <stdio.h>

int stack[50], cp;

void push(int n)
{
	stack[cp] = n;
	cp++;
}

int pop(void)
{
	cp--;
	return stack[cp];
}

int main(void)
{
	int n;
	cp = 0;
	
	while (scanf("%d", &n)) {
		if (n != 0)   push(n);
		else printf("%d\n", pop());
	}
	return 0;
}