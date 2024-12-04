#include<stdio.h>
int main(){
  int s,w;
  scanf("%d", &s);
  scanf(" %d", &w);
  if(s<=w){
    printf("unsafe");
  }else{
    printf("safe");
  }
  return 0;
}