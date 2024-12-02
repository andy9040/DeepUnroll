#include<stdio.h>
#include<string.h>
int main(void){
    char w[11],tw[50];
    int ans=0;
    scanf("%s",w);
    while(1){
        scanf("%s",tw);
        if(strcmp(tw,"END_OF_TEXT")==0){
            break ;
        }
        if(strcmp(tw,w)==0){
            ans++;
        }
    }
    printf("%d\n",ans);
    return 0;
}