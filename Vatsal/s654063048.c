#include<stdio.h>
int main()
{
  int A,B;
  scanf("%d %d",&A,&B);
  if(A-B*2>0){
    printf("%d\n",A-B*2);
  }else{
    printf("0\n");
  };
  return 0;
}