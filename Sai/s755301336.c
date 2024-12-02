#include<stdio.h>
int main(){
    int n;
    scanf("%d",&n);
    int ans = 0;
    for(int i = 1; i < (n + 1) / 2; i++)
        if(i != n - i)
            ans ++;
    printf("%d\n",ans);
    return 0;
}