#include<stdio.h>

int main(void){
    int p[101];
    int a,b,x,n,m,flag,count;
    scanf("%d %d",&x,&n);
    for(a = 0;a < n;a++){
        scanf("%d",&p[a]);
    }
    for(a = 0;a <= 60;a++){
        flag = 0;
        count = 0;
        for(b = 0;b < n;b++){
            if(x - a == p[b]){
                flag++;
            }
            if(x + a == p[b]){
                count++;
            }
        }
        if(flag == 0 || count == 0){
            if(flag == 0){
                m = x-a;
            }else{
                m = x+a;
            }
            break;
        }
    }
    printf("%d\n",m);
    
    /*d = x - a;
    e = x + a;
    int flagd = 0,flage = 0;
    for(b = 0;b < n;b++){
        if(d == p[b]){
            flagd++;
        }
        if(e == p[b]){
            flage++;
        }
    }
    if(flagd == 0){
        printf("%d\n",d);
    }else if(flage == 0){
        printf("%d\n",e);
    }*/
    return 0;
}
