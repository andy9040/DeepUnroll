#include <stdio.h>
#include <limits.h>
 
int main(void){
  int n;
  scanf("%d", &n);
  int min = INT_MAX;
  int max = INT_MIN;
  
  for(int i = 0; i < n; i++){
    int a;
    scanf("%d", &a);
    if(a < min) min = a;
    if(max < a) max = a;
  }
  
  printf("%d\n", max - min);
  return 0;
}