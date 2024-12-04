#include <stdio.h>
int main(){
    int a, b, c, k;
    int ans=0;
    scanf("%d%d%d%d",&a,&b,&c,&k);
    if(k>a){
        if(k-a-b>0){
            ans = a-(k-a-b);
        }else{
            ans = a;
        }
    }else{
        ans = k;
    }
    printf("%d\n",ans);
    return 0;
}