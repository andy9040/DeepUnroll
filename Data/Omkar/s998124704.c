#include<stdio.h>
int main(){
    int a[500]={0},i,kaisuu,k;
    int flg1,flg2,flg3,l;
    int j,cnt=0;
        cnt=0;
        a[500]={0};
        kaisuu=0;
    for(i=1;i<500;i++){
        scanf("%d",&a[i]);
        if(a[i]==0)break;
        cnt++;
    }
    kaisuu=cnt/5;
    for(i=0;i<kaisuu;i++){
        for(l=i*5+1;l<i*5+6;l++){
        if(a[l]==1)flg1=1;
        if(a[l]==2)flg2=1;
        if(a[l]==3)flg3=1;
        }
        if(flg1==1&&flg2==1&&flg3==1){
            for(j=1;j<6;j++){
                printf("3\n");
            }
            goto end;
        }
        if(flg1==1&&flg2==1){
            for(j=1;j<6;j++){
                if(a[i*5+j]==1)printf("1\n");
                else if(a[i*5+j]==2)printf("2\n");
                //printf("gu-");
            }
            goto end;
        }
        if(flg2==1&&flg3==1){
            for(j=1;j<6;j++){
                if(a[i*5+j]==2)printf("1\n");
                else if(a[i*5+j]==3)printf("2\n");
                //printf("pa-");
            }
            goto end;
        }
        if(flg1==1&&flg3==1){
            for(j=1;j<6;j++){
                if(a[i*5+j]==1)printf("2\n");
                else if(a[i*5+j]==3)printf("1\n");
                //printf("a-");
            }
            goto end;
        }
        end:
    flg1=0;
    flg2=0;
    flg3=0;
    }
    //printf("kaisuu = %d",kaisuu);
    return 0;
}