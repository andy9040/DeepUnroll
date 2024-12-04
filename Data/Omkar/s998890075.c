#include<stdio.h>

int main(){
    int n,k;
    scanf("%d %d",&n,&k);
    int ans=0;
    while(n>0){
        n/=k;
        ans++;
    }
    printf("%d",ans);
    return 0;
}