#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    int x, count = 0;
    int i;
    if(scanf("%d\n", &x) == EOF)
        return -1;
    char s[100];
    if(fgets(s, 100, stdin) == NULL)
        return -1;

    for(i = 0; i < x; i++){
        if(s[i] == '\n'){
            break;
        }
        count++;
        printf("%c", s[i]);
    }
    
    if(x == count && s[x] != '\n' && s[x-1] != '\n')
        printf("...\n");

    return 0;
}