#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#include<math.h>
#include<limits.h>
int main(){
    int X,N;
    (void)scanf("%d %d",&X,&N);
    int p[102];
    int f[102];
    memset(f,0,sizeof(f));
    for(int i=0;i<N;i++){
        (void)scanf("%d",p+i);
        f[p[i]] = 1;
    }
    int def = 0;
    for(;;){
        if(X-def<1){(void)printf("%d",X-def); return 0;}
        else if(X+def>100 && f[X-def]==0){printf("%d",X-def); return 0;}
        else if(X+def>100){(void)printf("%d",X+def); return 0;}
        else if(f[X-def]==0){(void)printf("%d",X-def);return 0;}
        else if(f[X+def]==0){(void)printf("%d",X+def);return 0;}
        else def++;
    }
}
