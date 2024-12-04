#include <stdio.h>

int main(int argc, const char * argv[]) {
    
    int a,b,c,k;
    scanf("%d %d %d %d",&a,&b,&c,&k);
    if(a>=k){
        printf("%d",k);
    }else if(a<k&&k<=a+b){
        k=a;
        printf("%d",k);
    }else{
        k=a-c;
        printf("%d",k);
    }
    
    return 0;
}
