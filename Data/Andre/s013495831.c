#include <stdio.h>


int main(void){
	int N,A,B,c;
    scanf("%d %d %d", &N, &A, &B);
    c = A * N;
    if(c > B){
        printf("%d\n", B);
    }else{
        printf("%d\n", c);
    }
}
