#include <stdio.h>

int main(void){
    long long int h;
    long long int w;
    scanf("%lld %lld",&h,&w);
    if(h==1 || w==1){
        printf("1");
    }
    else if((h*w)%2==1){
        printf("%lld",((h*w)/2)+1);
    }
    else{
        printf("%lld",(h*w)/2);
    }
    return 0;
}