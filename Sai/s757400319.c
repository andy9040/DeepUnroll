#include <stdio.h>

int n;

int dfs(int s){
  int ret, t, f1, f2, f3;

  if (s > n) {
    return 0;
  }

  t = s;
  f1 = 0;
  f2 = 0;
  f3 = 0;
  while (t > 0) {
    if (t % 10 == 7) {
      f1 = 1;
    }
    if (t % 10 == 5) {
      f2 = 1;
    }
    if (t % 10 == 3) {
      f3 = 1;
    }
    t = t / 10;
  }
  if (f1 == 1 && f2 == 1 && f3 == 1) {
    ret = 1;
  }
  else {
    ret = 0;
  }
  ret += dfs(s*10 + 7);
  ret += dfs(s*10 + 5);
  ret += dfs(s*10 + 3);
  return ret;
}

int main(void){

  scanf("%d", &n);

  printf("%d\n", dfs(0));

  return 0;
}
