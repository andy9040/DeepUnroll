#include<stdio.h>
int main()
{
  int N;
  scanf("%d", &N);

  int A[100];

  for(i=0;i<N;i++){
    scanf("%d", &A[i]);
  }

  for(i=0;i<N;i++){
    if(((a[i]%2 == 0)||((a[i]%3 == 0) && (a[i]%5 == 0))) && (a[i]%2 == 0)){
      printf("APPROVED\n");
    }
    else{
      printf("DENIED\n");
    }
  return 0;
}
