#include<stdio.h>
int main()
{
    int A, B, C;
    int K;

    scanf("%d %d %d", &A, &B, &C);
    scanf("%d", &K);

    for(int i=0; i<K; i++){
        if(C>B && B>A)
        {
            continue;
        }else if(C<=B && B>=A){
            C*=2;
        }else if(C<=B && B<=A){
            C*=2;
        }else if(C>=B && B<=A){
            B*=2;
        }
    }

    if(C>B && B>A){
        printf("Yes\n");
    }else{
        printf("No\n");
    }
    return 0;
}