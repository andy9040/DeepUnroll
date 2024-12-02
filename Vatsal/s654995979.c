#include<stdio.h>
int main(void){
    int a,b;
    char c;
    scanf("%d%c%d",&a,&c,&b);
    while(c!='?'){
        if(c=='+'){
            printf("%d\n",a+b);
        }else if(c=='-'){
            printf("%d\n",a-b);
        }else if(c=='*'){
            printf("%d\n",a*b);
        }else if(c=='/'){
            printf("%d\n",a/b);
        }
    }
    return 0;
}