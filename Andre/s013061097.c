#include <stdio.h>

int main(){
    int a,b,c;
    scanf("%d %d %d", &a,&b,&c);

    if((!(0<=a<=100)) | (!(0<=b<=100)) | (!(0<=c<=100)) | (a==b) | (a==c) | (b==c))return 0;

    if(a<c && c<b)printf("Yes");
    else printf("No");

    return 0;
}