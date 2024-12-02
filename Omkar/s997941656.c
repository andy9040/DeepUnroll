#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void){
    int k;
    scanf("%d",&k);
    char s[100];
    scanf("%s",s);
    
    int size = strlen(s);
    if(k>=size){
    printf("%s",s);
    }
    else{
    s[k]='\0';
    printf("%s...",s);  
    }
    return 0;
}