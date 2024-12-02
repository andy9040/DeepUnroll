#include<stdio.h>



int main(){
   int a[5],b[13];
   while(scanf("%d,%d,%d,%d,%d",&a[0],&a[1],&a[2],&a[3],&a[4])!=EOF){
      for(int i=0;i<13;i++){b[i]=0;}
      for(int i=0;i<5;i++){ b[a[i]-1]++;}
      
      for(int i=0;i<13;i++){
         if(b[i]==4){
            printf("four card\n");
            goto exit;
         }
      }

      for(int i=0;i<13;i++){
         for(int j=0; j<13;j++){
            if(b[i]==2&&b[j]==3){
               printf("full house\n");
               goto exit;
            }else if(b[i]==2&&b[j]==2){
               printf("two pair\n");
               goto exit;
            }
            
         }
      }


     for(int i=0;i<13;i++){
        if(b[i]==3){printf("three card\n");goto exit;}
        else if(b[i]==2){printf("two pair\n"); goto exit;}
     }

     for(int i=0;i<9;i++){
        if(b[i]==1&&b[i+1]==1&&b[i+2]==1&&b[i+3]==1&&b[i+4]==1){
           printf("straight\n");
           goto exit;
        }
     }

     if(b[0]==1&&b[9]==1&&b[10]==1&&b[11]==1&b[12]==1){printf("straight\n"); goto exit;}

     printf("null\n");

     exit:;
      
     
   }
}