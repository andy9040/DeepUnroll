#include<stdio.h>
int main(){
	int x, y, hasil;
	scanf("%d %d", &x, &y);
	if ( x + y > 24){
		hasil = x + y - 24;
		printf("%d", hasil);
	}else{
		hasil = x + y;
		printf("%d", hasil);
	}
	return 0;
}