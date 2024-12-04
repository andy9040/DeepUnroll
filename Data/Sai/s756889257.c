#include <stdio.h>

int main(){
    long long int H,W,S;
    scanf("%lld",&H);
    scanf("%lld",&W);
    if(H ==1 || W==1){ printf("%d",1);
    return 0;
    }
    if(W%2==0){
            S=(W/2)*H;
    }
    else{
        if(H%2==0){
            S=W*H/2;
        }
        else{
            S=W*(H/2)+W/2+1;
        }
    }
    printf("%lld",S);
    return 0;
}