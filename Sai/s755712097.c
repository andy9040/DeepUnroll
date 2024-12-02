#include <stdio.h>

int main()
{
        int a,b,i,flag = 1;
        scanf("%d %d",&a,&b);
        char S[100];
        scanf("%s",S);
        for(i = 0;i<a;i++){
                if(S[i]<'0'||S[i]>'9')        flag = 0;
        }
        if(S[b] != '-') flag = 0;
        for(i = b+1;i<a+b+1;i++){
                if(S[i]<'0'||S[i]>'9')        flag = 0;
        }
        if(flag == 1)   printf("Yes");
        else            printf("No");
        return 0;
}
