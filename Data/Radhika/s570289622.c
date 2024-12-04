#include<stdio.h>
#include<string.h>
int main(){
    int k;
    char s[100+1];
    scanf("%d",&k);
    scanf("%s",s);
    if(strlen(s)<=k){
        printf("%s",s);
        return 0;
    }else if(k<strlen(s)){
        for(int i=0;i<k;i++){
            printf("%c",s[i]);
        }
    }
    printf("...\n");
}