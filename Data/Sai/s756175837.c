#include <stdio.h>

int main(){
    char a[10]={0};
    char*b = "YAKI";
    scanf("%s", a) ;
    int i;
    for(i =0; i<4; i++){
        if(a[i]!=b[i]){
            printf("No\n");
            return 0;
        }
    }
    printf("Yes\n");
    return 0;
}