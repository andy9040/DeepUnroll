#include<stdio.h>

int main(){

    int a,b;
    int c;
    scanf("%d %d",&a,&b);
    if(a+b>=24){
        c = (a+b)-(((a+b)/24)*24);
        printf("%d\n",c);
    }
    else {
        c = a+b;
        printf("%d\n",c);
    }

return 0;
}
