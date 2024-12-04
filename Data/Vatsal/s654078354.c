#include<stdio.h>
#define true 1
#define false -1

int A(int x,int y);

int a[2000],b[2000],c;

int main(){
    int d,e,i;
    char f[2][4]={"yes","no"};
    
    scanf("%d",&c);
    for(i=0;i<c;i++){
        scanf("%d",&a[i]);
    }
    
        scanf("%d",&d);
    for(i=0;i<d;i++){
        scanf("%d",&b[i]);
    if(A(0,b[i]))==ture){
        printf("%s\n",f[0]);
    }else{
        printf("%s\n",f[1]);
    }
    return 0;
}

int A(int x,int y){
    int z;
    if(y==0){
        return ture;
    }
    if(x>=c){
        return ture;
    }
    if(A(x+1,y)==ture){
        z=ture;
    }else if(A(x+1,y-a[x])==ture){
        z=ture;
    }else{
        z=false;
    }
    return z;
}
