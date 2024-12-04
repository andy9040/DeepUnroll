#include <stdio.h>
#include <string.h>

int main(int argc,const char *argv[]){
    int i,n,hanako_point,tarou_point,result;
    
    
    scanf("%d",&n);
    
    for(i=0;i<n;i++){
        char hanako[101]={};
        char tarou[101]={};
        scanf("%s %s",hanako,tarou);
        result=strcmp(hanako,tarou);
        
        if(result==0){
            hanako_point++;
            tarou_point++;
        }else if(result>0){
            hanako_point+=3;
        }else{
            tarou_point+=3;
        }
        
    }
    printf("%d %d\n",tarou_point,hanako_point);
    return 0;
}