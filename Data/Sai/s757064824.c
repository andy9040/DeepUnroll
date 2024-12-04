#include <stdio.h>
int main(){
    int N;
    int a=0;
    
    char W[128][16];
    scanf("%d",&N);
    for(int i = 0; i<N; i++){
        scanf("%s",W[i]);
    }
    for(int i = 0; i<N; i++){
        int x=0;
        for(int j = 0; j<N; j++){
            int y=0;
            for(int n = 0; n<16; n++){
                if (W[i][n]==W[j][n]){y++;}
            }
            if(y==16){x++;}
        }
        if(x==1){}else{a=1;}
    }
    
    
    
    int x=0;
    for(int i = 0; i<N; i++){
        int k;
        for(int j = 0; j<16; j++){
            k=j;
            if(W[i][j]==0){break;}
        }
        if(W[i][k-1]==W[i+1][0]){}else{
            x++;
        }
        if(x==1){}else{a=1;}
    }
    
    if(a==0){printf("Yes");}
    if(a==1){printf("No");}
    return 0;
}