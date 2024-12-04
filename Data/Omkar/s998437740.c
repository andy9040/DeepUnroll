#include <stdio.h>
int main(void){
    // Your code here!
    int N,A,B;
    scanf("%d %d %d",&N,&A,&B);
    printf("%d %d\n",(A<B)? A:B,(N<A+B)? A+B-N:0);
}
