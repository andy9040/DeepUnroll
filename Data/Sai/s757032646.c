#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main(void){ 
    long i,H,W,a;
        scanf("%ld%ld",&H,&W);
        if(H%2 == 0){
            a = (H/2)*W;
            printf("%ld\n",a);
        }
        else{
            a = (H/2)*W + (W + 1)/2;
            printf("%ld\n",a);
        }
    
    return 0;
} 