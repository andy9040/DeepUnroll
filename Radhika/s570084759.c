#include <stdio.h>
#include <string.h>

int main(){
    char com[20];
    int i,j,k,j1,n,data;
    int Q[1000000]={0};
    
    char delete[]="delete";
    char insert[]="insert";
    char first[]="deleteFirst";
    char last[]="deleteLast";
    
    scanf("%d",&n);
    i=0;
    for(;n>0;n--){
        scanf("%s",com);
        if(strcmp(com,insert)==0){
            i++;
            scanf("%d",&data);
            for(j=i;j>0;j--)Q[j]=Q[j-1];
            Q[0]=data;
            //printf("1\n");
        }else if(strcmp(com,delete)==0){
            scanf("%d",&data);
            for(j=1;j<=i;j++){
                if(Q[j]==data)break;
            }
            for(k=j;k<=i;k++){
                Q[k]=Q[k+1];
            }
            Q[i]=0;
            i--;
            //printf("2\n");
        }else if(strcmp(com,first)==0){
            for(j=0;j<=i;j++){
                Q[j]=Q[j+1];
            }
            Q[i]=0;
            i--;
            //printf("3\n");
        }else if(strcmp(com,last)==0){
            Q[i]=0;
            i--;
            //printf("4\n");
        }
    }
    for(j1=0;j1<i-1;j1++)printf("%d ",Q[j1]);
    printf("%d\n",Q[i-1]);
    return 0;
}