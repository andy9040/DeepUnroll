#include <stdio.h>
#include <stdlib.h>

int main(void){
    int i,x,n,min = 101,ansmin,ansplus, result,s[101];
    scanf("%d%d",&x,&n);
    int a[n];

    if(n==0){
        printf("%d",x);
        return 0;
    }

    for(i=0;i<101;i++){
        s[i] = i+1;
    }

    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
        s[a[i]-1] = 0;
    }

    for(i=0;i<n+1;i++){
        if(min > abs(x-a[i])){
            min = abs(x-a[i]);
            ansmin = a[i]-1;
            ansplus = a[i]-1;
        }
    }

    while(1){
        if(s[--ansmin] != 0){
            result = ansmin;
            break;
        }else if(s[++ansplus] != 0){
            result = ansplus;
            break;
        }
    }

    printf("%d",s[result]);
    return 0;
}