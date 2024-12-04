#include<stdio.h>
#include<string.h>
int main(void)
{
    char S[11];
    int A,B;
    int i,j=0,k=0;
  
    scanf("%d%d",&A,&B);
    scanf("%s",S);
  
    if(strlen(S)!=A+B+1) { printf("No\n"); return 0; }
    for(i=0;i<strlen(S);i++){
      if((S[i]>='0')&&(S[i]<='9')) j++;
      else if(S[i]=='-') k++;
      else { printf("No\n"); return 0; }
    }
    if(k==1) { printf("Yes\n"); return 0; }
    else { printf("No\n"); return 0; }
}