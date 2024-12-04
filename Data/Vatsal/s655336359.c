#include<stdio.h>
int main(){

    int N , D ;
    scanf("%d%d",&N,&D);
    int i = D+1 ; int count = 0 ;
    while(i <= N){
        count++;
        if(N >= 2*i){
            i = 2*i ;
        }
        else{
            i = i + (N-(D+1));
            }
    }
    printf("%d",count) ;
}
