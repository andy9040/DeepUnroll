#include<stdio.h>
#include<string.h>

int main(){
  
  int N;
  scanf("%d",&N);

  int a = 0;
  int b = 0;
  int sum = 0;

  for(int i=0; i<N; i++){
    scanf("%d %d",&a,&b);
    sum = b - a + 1;
  }

  printf("%d",sum);

  return 0;

}