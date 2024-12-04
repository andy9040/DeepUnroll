#include <stdio.h>
#include <string.h>

int main(void){
    // Your code here!
    char S[200001],T[200001],slist[26] = {0},tlist[26] = {0},scount = 1,tcount = 1,flag = 1;
    int n;
    scanf("%s",S);
    scanf("%s",T);
    n = strlen(S);
    slist[S[0]-97] = scount++;
    S[0] = 1;
    tlist[T[0]-97] = tcount++;
    T[0] = 1;
    for(int i = 1; i < n && flag == 1; i++)
    {
        if(slist[S[i]-97] == 0)
            slist[S[i]-97] = scount++;
        
        S[i] = slist[S[i]-97];
        
        if(tlist[T[i]-97] == 0)
            tlist[T[i]-97] = tcount++;
        
        T[i] = tlist[T[i]-97];
        
        if(S[i] != T[i]) flag = 0;
    }
    printf("%s\n",(flag == 1)? "Yes":"No");
}
