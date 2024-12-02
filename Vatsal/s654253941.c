#include <stdio.h>
int main(){
  int a,b,alice,bob;
  scanf("%d %d",&a,&b); //入力

  if(a==b){  //引き分け
    printf("Draw\n");
    return 0;
  }

  if(a>b){
    if(b==1){
      printf("Bob\n");
    }
    else{
      printf("Alice\n");
    }
  }

  if(a<b){
    if(a==1){
      printf("Alice\n");
    }
    else{
      printf("Bob\n");
    }
  }
  return 0;
}