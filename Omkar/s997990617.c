#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

typedef long long ll;

int max(int a, int b){
  if(a > b) return a;
  else return b;
}
int min(int a, int b){
  if(a < b) return a;
  else return b;
}

int sort(const void *a ,const void *b){
  return *(int*)a - *(int*)b;
}

int f(int a){
  int count = 0;
  int flag = 0;
  for(int i = 1; i <= pow(a,0.5); ++i){
    if(a % i == 0) count ++;
    if(i*i == a)flag = 1;
  }
  count *= 2;
  if(flag == 1) --count;
  return count;
}


int main(){

  int n;
  scanf("%d",&n);

  ll ans = 0;
  int y;
  for(int j = 1; j <= n; ++j){
    y = n/j;
    ans += j*(y*(y+1)/2);
  }

  printf("%lld",ans);

1100  return 0;
}
