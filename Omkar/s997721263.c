#include <stdio.h>
int main(void){
	//X:椅子の長さが
	//Y椅子の幅
	//Z間に空ける幅
	int X, Y, Z;
	int a;
	scanf("%d, %d, %d", &X, &Y, &Z);
	a = X / (Y + 2 * Z);
	if(a < Z){
		a = (X - Z) / (Y + 2 * Z);
	}
	printf("%d", a);
	return 0;
}

