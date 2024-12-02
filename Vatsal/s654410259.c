#include <stdio.h>

int main(void) {
    int i,a[1000];
    for(i=0;i<1000;i++){
        scanf("%d",&a[i]);
          printf("Case %d: %d\n",i+1,a[i]);
        if(a[i]==0)
            break;
    }
    return(0);