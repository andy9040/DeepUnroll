#include<stdio.h>

int main(){
  int a, b, c, k;
  scanf("%d %d %d %d", &a, &b, &c, &k);
  int i, total=0;

  if(a>k){
    printf("%d\n", total+k);
    return 1;
  }else
    total+=a;

  i=a+b;
  if(i>=k){
    printf("%d\n", total);
    return 1;
  }
  
  printf("%d\n", total-(k-i));
  return 0;
}
