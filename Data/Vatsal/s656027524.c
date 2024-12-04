#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>
#include <stdlib.h>

#define SIZE (2*10*10*10*10*10)

char S[SIZE];
int  g[SIZE];

void do_magic(char t, char d, int N)
{
  int i;
  int tmp_g;

  if (d == 'L') {
    for (i=0; i<N; i++) {
      //printf("L pre  d=%c S[%d]=%c g[%d]=%d\n", d, i, S[i], i, g[i]);
      if (S[i] == t) {
        tmp_g = g[i];
        g[i] = 0;
        if (i > 0){
          g[i-1] += tmp_g;
        }
      }
      //printf("L post d=%c S[%d]=%c g[%d]=%d\n", d, i, S[i], i, g[i]);
    }

  } else {// 'R'

    for (i=(N-1); i>=0; i--) {
      //printf("R pre  d=%c S[%d]=%c g[%d]=%d\n", d, i, S[i], i, g[i]);
      if (S[i] == t) {
        tmp_g = g[i];
        g[i] = 0;
        if (i < (N-1)) {
          g[i+1] += tmp_g;
        }
      }
      //printf("R post d=%c S[%d]=%c g[%d]=%d\n", d, i, S[i], i, g[i]);
    }
    
  }

  return;
}

int main()
{
  int cnt;
  int N,Q;
  int i;
  char t;
  char d;
  int  total_g = 0;

  cnt = scanf("%d %d", &N, &Q);
  cnt = scanf("%s", S);

  for (i=0; i<N; i++) {
    g[i] = 1;
  }

  for (i=0; i<Q; i++) {
    cnt = scanf("%c %c", &t, &d);
    do_magic(t, d, N);
  }

  for (i=0; i<N; i++) {
    total_g += g[i];
  }

  printf("%d", total_g);

  return 0;
}
