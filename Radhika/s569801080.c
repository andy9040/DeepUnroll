#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

typedef long long ll;

int main(){
  int a,b,c;
  int sum = 0;
  int k;

  scanf("%d %d %d %d", &a, &b, &c, &k);

  if(a >= k){
    printf("%d\n", a);
    return 0;
  }

  if(a < k){
    k = k - a;
    sum += a;

    if(b >= k){
      printf("%d\n", sum);
    }

    else printf("%d\n", sum - k + b);
  }

  return 0;
}
