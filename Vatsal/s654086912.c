#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include <limits.h>

int sort(const void *a, const void *b){
    return *(int*)a-*(int*)b ;
}

int main(void){
    char s[200020],t[200020];
    char lowcmp[27]="abcdefghijklmnopqrstuvwxyz";
    scanf("%s%s",s,t);
    int to[27];
    for (int i=0; i<27; i++){
        to[i]=i;
    }
    bool visited[27];
    for (int i=0; i<strlen(s); i++){
        int a,b;
        for (int j=0; j<27; j++){
            if (lowcmp[j]==s[i]){
                a=j;
            }
            if (lowcmp[j]==t[i]){
                b=j;
            }
        }
        while (a!=to[a]){
            a=to[a];
        }
        if (a!=b && visited[b]==true){
            printf("No\n");
            return 0;
        } 
            
        visited[b]=true;
        to[a]=b;
    }
    printf("Yes\n");
    return 0;
}