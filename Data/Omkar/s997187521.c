#include <stdio.h>
#include <math.h>

int main(void){
    int i,j,n,a,b,x=1;
    int c=1;
    scanf("%d %d %d\n",&n,&a,&b);
    
    if(n%2==0){
        for(i=1;i<=n/2;i++){
            c*=(n+1-i)/i;
        }
        x+=c;
        
        for (j=1;j<n/2;i++){
            c=1;
            for(i=1;i<=j;i++){
                c*=(n+1-i)/i;
            }
            x+=2*c;
        }
        
    }else{
        for (j=1;j<n/2;i++){
            c=1;
            for(i=1;i<=j;i++){
                c*=(n+1-i)/i;
            }
            x+=2*c;
        }
    }
    
    int ca=1;
    for(i=1;i<=a;i++){
        ca*=(n+1-i)/i;
    }
    int cb=0;
    for(i=1;i<=b;i++){
        cb*=(n+1-i)/i;
    }
    x=x-ca-cb;
    printf("%d\n",x);
    
    
    return 0;
}
