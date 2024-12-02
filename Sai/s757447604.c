#include <stdio.h>

int main(void){
  int i, j;

  int n;
  scanf("%d", &n);

  int max1, max2, temp;
  long sum=0;
  int p[n];
  for(i=0; i<n; i++){
    scanf("%d", &p[i]);
    if(i == 0) continue;
    max1=p[i], max2=0, temp=0;
    for(j=i-1; j>=0; j--){
      if(p[j] > max1){
        max2=max1;
        max1=p[j];
      }else if(p[j] > max2){
        max2=p[j];
      }
      sum += max2;
    }
  }

  printf("%ld\n", sum);
}
