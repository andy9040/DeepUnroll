#include<stdio.h>

int main(void)
{
  int A,B,C;
  printf("A,B,Cの文節の長さを入力：");
  scanf("%d,%d,%d",&A,&B,&C);
  if(A+B+C!=17){
    printf("NO");
  }else{
    if(max(A,B,C)==7){
      if(min(A,B,C)==5){
        printf("YES");
      }else{printf("NO");
           }
    }
  }
return 0;
}