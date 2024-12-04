#include<stdio.h>

int main(){
    int T[11], num, state = 0;
    while(scanf("%d", &num) != EOF){
        if(num){
            T[state] = num;
            state++;
        }else{
            state--;
            printf("%d\n", T[state]);
        }
    }

}