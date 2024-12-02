#include <stdio.h>

int A,B;

void input(void){
	scanf("%d %d",&A,&B);

}

int main(void){
	input();	

	if (A == 1) A = 14;
	if (B == 1) B = 14;

	if(A==B){printf("Draw");
	}else if(A>B){printf("Alice");
	}else{printf("Bob");
	}
	
	return 0;
}