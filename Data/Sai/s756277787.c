#include <stdio.h>
#include <stdlib.h>

int ans = 0;

void a(int count){
    if (count > ans){
        ans = count;
    }
}

int main(){
    char str[12];
    
    scanf("%s", &str);
    
    int idx = 0;
    
    int count = 0;

    while(str[idx] != '\0'){
        switch(str[idx]){
            case 'A':
            case 'C':
            case 'T':
            case 'G':
                count++;
                break;
            default:
                a(count);
                count = 0;
        }
        idx++;
    }
    
    if (count > ans){
        ans = count;
    }
    
    printf("%d", ans);
        
    return 0;
}