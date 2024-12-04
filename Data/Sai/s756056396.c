#include <stdio.h>
#include <string.h>

int main(){
    char i[10];
    int len;
    int a,b,c = 0;

    scanf("%s" ,i);

    len = strlen(i);

    for(a = 0; a < len; a++){
        if(i[a]=='A'|| i[a]=='C' || i[a]=='G' || i[a]=='T'){
            b++;
        }
        else{
             if(b > c){
                 c = b;
            }
            b = 0;
        }
    } 

    if(b > c){
        c = b;
    }  
    printf("%d\n", c);
    return 0;  
}