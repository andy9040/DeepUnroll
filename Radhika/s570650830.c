#include<stdio.h>

int main(void){
  int a,b,c;
  scanf("%d %d %d", &a, &b, &c);
  
  if(a<c && b>c){
    printf("Yes");
  }else if(a>c && b<c){
    printf("Yes");
  }else{
    printf("No");
  }
}
