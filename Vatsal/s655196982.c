#include <stdio.h>
#include <string.h>

int main(void){
    char S[200000];
    char T[200000];
    memset(&S,'\0',sizeof(S));
    memset(&T,'\0',sizeof(T));
    scanf("%s",S);
    scanf("%s",T);
    
    int size = strlen(S);

    char tmpS;
    char tmpT;

    for(int i = 0;i<size;i++){
        if(S[i] != T[i]){
            tmpS = S[i];
            tmpT = T[i];
            // printf("%c\n",tmpS);
            // printf("%c\n",tmpT);
            for(int j = 0;j<size;j++){
                // printf("S %s\n",S);
                if(S[j] == tmpS){
                    S[j] = tmpT;
                    // printf("S[j] %c j %d\n",S[j],j);
                    continue;
                }
                if(S[j] == tmpT){
                    S[j] = tmpS;
                    // printf("S[j] %c j %d\n",S[j],j);
                }
            }
        }
        if(strcmp(S,T) == 0){
            printf("Yes\n");
            return 0;
        }
    }
    printf("No\n");
    // printf("S %s\n",S);
    // printf("T %s\n",T);
    return 0;
}