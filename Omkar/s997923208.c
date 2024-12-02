#include <stdio.h>
#include <stdlib.h>

int a[100000];

int Cmp(const void *a, const void *b){
  return *(int *)a - *(int *)b;
}

int Check(int N){
  int i, c;
  int cn[3], n[3];
  for(i = 0;i < 3;i++) cn[i] = 0;
  c = cn[0] = 1;
  n[0] = a[0];
  for(i = 1;i < N;i++){
    if(a[i-1] == a[i]) cn[c-1]++;
    else{
      c++;
      if(c == 4) return 0;
      n[c-1] = a[i];
      cn[c-1]++;
    }
  }
  if(c == 1){
    if(n[0] != 0) return 0;
    else return 1;
  }
  if(c == 2){
    if(n[0] != 0) return 0;
    else{
      if(N % 3 != 0) return 0;
      if(cn[1] == N * 2 / 3 && cn[0] == N / 3) return 1;
      else return 0;
    }
  }
  if(n[0] == 0) return 0;
  if(N % 3 != 0) return 0;
  for(i = 0;i < 3;i++) if(cn[i] != N / 3) return 0;
  if(n[0] != (n[1] ^ n[2])) return 0;
  else return 1;
}

void Do(int N){
  int i;
  for(i = 0;i < N;i++) scanf("%d", &a[i]);
  qsort(a, N, sizeof(int), Cmp);
  if(Check(N) == 1) printf("Yes\n");
  else printf("No\n");
}

int main(void){
  int N;
  scanf("%d", &N);
  Do(N);
  return 0;
}
