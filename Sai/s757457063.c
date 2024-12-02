#include <stdio.h>
int main(){
    int N,D;
    scanf("%d %d",&N,&D);
    if(N%(2*D+1)==0){
        printf("%d",N/(2*D+1));
        return 0;
    }
    printf("%d",N/(2*D+1)+1);
}