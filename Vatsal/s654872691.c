#include<stdio.h>
#include<string.h>
int main(){
  int sum = 0, l, r, n;
  scanf("%d", &n);
  for(int i = 0; i < n; ++i){
    scanf("%d %d", &l, &r);
    sum += 1 + r - l;
  }
  printf("%d\n", sum);
  return 0;
}