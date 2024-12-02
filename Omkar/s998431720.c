#include<stdio.h>
void main(){
  int s , w;
  scanf("%d",&s);
  scanf("%d",&w);
  if(w>=s){
    printf("unsafe\n");
  }
  else{
    printf("safe\n");
  }
}