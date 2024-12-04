#include <stdio.h>
int judge(char left[],char s[]){
    int i,j,count=0,k=0;
    for(i=0;left[i]!=0;i++)
        if(left[i]==s[0])
            k=1;
   
    for(j=1;s[j]!=0;j++)
        for(i=0;left[i]!=0;i++){
            if(left[i]==s[j]){
           
                if(k==0){
                count++;
           
                k=1;
                }
                break;
            }
            else{
                if(k==1&&i==14){
                    count++;
     
                    k=0;
                }
            }
        }
    return count;
}
int main(void){
    char s[100],left[]="qwertasdfgzxcvb";
    
    while(1){
        scanf("%s",s);
        if(s[0]=='#')
            break;
        printf("%d\n",judge(left,s));
    }
    return 0;
}