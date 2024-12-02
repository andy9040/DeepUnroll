#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    int m,n,a[2000]={},i,count=0,sum=0;
    char token[3000000]={};
    fgets(token, sizeof(token), stdin);
    n=atoi(strtok(token, " "));m=atoi(strtok(NULL, " "));
    fgets(token, sizeof(token), stdin);
    a[0]=atoi(strtok(token, " "));sum+=a[0];
    for (i=1; i<n; i++) {
        a[i]=atoi(strtok(NULL, " "));
        sum+=a[i];
    }
    for (i=0; i<n; i++) {
        if(sum/(4*m)<a[i]) count++;
    }
    if (count>=m) printf("Yes");
    else printf("No");
    return 0;
}


